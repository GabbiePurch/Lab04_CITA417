// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ObstacleCourseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LAB04_CITA417_API AObstacleCourseGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:

    AObstacleCourseGameMode();

    UFUNCTION(BlueprintCallable, Category = "Course")
    void PlayerFailed();

    UFUNCTION(BlueprintCallable, Category = "Course")
    void CourseCompleted();

    UFUNCTION(BlueprintPure, Category = "Course")
    int32 GetAttemptCount() const;


private:

	int32 AttemptCount = 1;

    bool bCourseCompleted = false;
	
};
