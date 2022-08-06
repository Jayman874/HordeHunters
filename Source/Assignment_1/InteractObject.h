// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractObject.generated.h"

UCLASS()
class ASSIGNMENT_1_API AInteractObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractObject();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractObject")
	float FloatSpeed = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractObject")
	float RotationSpeed = 20.0f;
	
	UPROPERTY(EditAnywhere, Category = "RemoveActor")
	bool bDisableActor;

	UFUNCTION(BlueprintCallable, Category = "RemoveActor")
	void RemoveActor(bool Remove);
		
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
protected:	virtual void Tick(float DeltaTime) override;

};
