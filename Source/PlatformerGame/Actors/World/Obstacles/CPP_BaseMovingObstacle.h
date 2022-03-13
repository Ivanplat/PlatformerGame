// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BaseObstacle.h"
#include "Components/TimelineComponent.h"
#include "CPP_BaseMovingObstacle.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_BaseMovingObstacle : public ACPP_BaseObstacle
{
	GENERATED_BODY()
public:
	ACPP_BaseMovingObstacle();
public:
	virtual void Tick(float DeltaSeconds) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstacle's Variables")
	FRotator ObstacleRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstacle's Variables", meta = (MakeEditWidget))
	FTransform ObstacleStartPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstacle's Variables", meta = (MakeEditWidget))
	FTransform ObstacleEndPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Components")
	class UTimelineComponent* TimelineComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Components")
	class USceneComponent* MovingSpace;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timeline Variables")
	class UCurveFloat* TimelineFloatCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timeline Variables")
	bool Played = false;
protected:
	class FOnTimelineFloat TimelineInterp;
	class FOnTimelineEvent TimelineEnd;
protected:
	UFUNCTION()
	virtual void OnTimelineInterp(float Value);
	UFUNCTION()
	virtual void OnTimelineEnd();
protected:
	virtual void MoveObstacle();
	virtual void BeginPlay() override;
};
