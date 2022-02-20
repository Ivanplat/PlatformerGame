// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BasePlatform.h"
#include "CPP_DisappearingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_DisappearingPlatform : public ACPP_BasePlatform
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Disappearing Platform Variables")
	float TimeToShow = 1.0f;
private:
	FTimerHandle PlatformTimerHandle;
protected:
	virtual void BeginPlay() override;
protected:
	UFUNCTION()
	virtual void ShowPlatform();
};
