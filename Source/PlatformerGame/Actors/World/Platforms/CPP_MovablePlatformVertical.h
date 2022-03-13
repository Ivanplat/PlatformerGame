// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MovablePlatform.h"
#include "CPP_MovablePlatformVertical.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_MovablePlatformVertical : public ACPP_MovablePlatform
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform's Variables", meta = (MakeEditWidget))
	FTransform StartPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform's Variables", meta = (MakeEditWidget))
	FTransform EndPoint;
protected:
	virtual void OnTimelineInterp(float Value) override;
};
