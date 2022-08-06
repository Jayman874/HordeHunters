// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractObject.h"

// Sets default values
AInteractObject::AInteractObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    VisualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> UpgradeAsset(TEXT("/Game/Game/Props/SM_billboard_forSale.SM_billboard_forSale"));

    if (UpgradeAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(UpgradeAsset.Object);
        VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

}

// Called when the game starts or when spawned
void AInteractObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (bDisableActor) {
        RemoveActor(bDisableActor);
    }
	
    FVector Location = GetActorLocation();
    FRotator Rotation = GetActorRotation();
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    Location.Z += DeltaHeight * FloatSpeed;
    float DeltaRotation = DeltaTime * RotationSpeed;
    Rotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(Location, Rotation);
}

void AInteractObject::RemoveActor(bool bDisable)
{
    SetActorHiddenInGame(bDisable);
	SetActorEnableCollision(!bDisable);
    SetActorTickEnabled(!bDisable);
	
}

