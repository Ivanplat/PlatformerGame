// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BaseButton.h"
#include "CPP_ButtonForPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_ButtonForPlatform : public ACPP_BaseButton
{
	GENERATED_BODY()
protected:
	virtual void ImplementsButton() override;
protected:
	UPROPERTY(EditAnywhere, Category="Button's Variables")
	TArray<class ACPP_MovablePlatformFromButton*> PlatformsToHandle;
public:
	friend class ACPP_MovablePlatformWithButton;
};
