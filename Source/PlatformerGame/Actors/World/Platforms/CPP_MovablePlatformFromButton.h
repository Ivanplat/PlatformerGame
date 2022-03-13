// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MovablePlatform.h"
#include "CPP_MovablePlatformFromButton.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_MovablePlatformFromButton : public ACPP_MovablePlatform
{
	GENERATED_BODY()
public:
	ACPP_MovablePlatformFromButton();
protected:
	virtual void ImplementsPlatform() override;
protected:
	friend class ACPP_ButtonForPlatform;
};
