// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BasePlatform.h"
#include "Components/TimelineComponent.h"
#include "CPP_MovablePlatform.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_MovablePlatform : public ACPP_BasePlatform
{
	GENERATED_BODY()
public:
	ACPP_MovablePlatform();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Components")
	class UTimelineComponent* TimelineComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timeline Variables")
	class UCurveVector* TimelineVectorCurve;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timeline Variables")
	bool Played = false;
protected:
	class FOnTimelineVector TimelineInterp;
	class FOnTimelineEvent TimelineEnd;
protected:
	virtual void BeginPlay() override;
protected:
	UFUNCTION()
	virtual void OnTimelineInterp(FVector InVector);
	UFUNCTION()
	virtual void OnTimelineEnd();

};
