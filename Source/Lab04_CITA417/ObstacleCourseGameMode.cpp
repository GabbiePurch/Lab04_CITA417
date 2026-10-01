// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleCourseGameMode.h"

// Fill out your copyright notice in the Description page of Project Settings.

#include "ObstacleCourseGameMode.h"


AObstacleCourseGameMode::AObstacleCourseGameMode()
{
    AttemptCount = 1;

    UE_LOG(LogTemp, Warning, TEXT("Obstacle Course Started - Attempt %d"), AttemptCount);
}


void AObstacleCourseGameMode::PlayerFailed()
{
    AttemptCount++;

    UE_LOG(LogTemp, Warning, TEXT("Player Failed - Starting Attempt %d"), AttemptCount);
}


void AObstacleCourseGameMode::CourseCompleted()
{
    if (bCourseCompleted)
    {
        return;
    }

    bCourseCompleted = true;

    UE_LOG(
        LogTemp,
        Warning,
        TEXT("COURSE COMPLETE! Finished on Attempt %d"),
        AttemptCount
    );
}


int32 AObstacleCourseGameMode::GetAttemptCount() const
{
    return AttemptCount;
}