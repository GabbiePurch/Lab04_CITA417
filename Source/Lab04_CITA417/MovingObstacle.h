// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MovingObstacle.generated.h"

UCLASS()
class LAB04_CITA417_API AMovingObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingObstacle();

	//Creating a reference Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Obstacle")
	UStaticMeshComponent* ObstacleMesh;

	// Adding Movement
	//MovementOffset tells the obstable how far to move
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MovementOffset = FVector(0.0f, 300.0f, 0.0f);

	// MovementSpeed tell the obstacle how fast to move
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 100.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// Stores where the object was first placed in the world.
	FVector StartLocation;

	// Tells us where it's moving, away from styart to back to start.
	bool bMovingForward = true;

};
