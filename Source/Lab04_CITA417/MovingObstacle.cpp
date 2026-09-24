// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObstacle.h"

// Sets default values
AMovingObstacle::AMovingObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(
		TEXT("ObstacleMesh")
	);

	RootComponent = ObstacleMesh;

	ObstacleMesh->SetMobility(EComponentMobility::Movable);

	ObstacleMesh->SetCollisionEnabled(
		ECollisionEnabled::QueryAndPhysics
	);

	ObstacleMesh->SetCollisionResponseToAllChannels(ECR_Block);

}

// Called when the game starts or when spawned
void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();


	// Debug message to the console
	UE_LOG(
		LogTemp,
		Warning,
		TEXT("Moving Obstacle initialized at: %s"),
		*StartLocation.ToString()
	);
	
}

// Called every frame
void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // Calculate the two positions
    FVector EndLocation = StartLocation + MovementOffset;

    FVector CurrentLocation = GetActorLocation();

    // Determine which position we are moving toward
    FVector TargetLocation;

    if (bMovingForward)
    {
        TargetLocation = EndLocation;
    }
    else
    {
        TargetLocation = StartLocation;
    }

    // Move toward the target at a constant speed
    FVector NewLocation = FMath::VInterpConstantTo(
        CurrentLocation,
        TargetLocation,
        DeltaTime,
        FMath::Max(0.0f, MovementSpeed)
    );

    SetActorLocation(NewLocation);

    // Reverse direction when we reach the target
    if (NewLocation.Equals(TargetLocation, 1.0f))
    {
        bMovingForward = !bMovingForward;
    }

}

