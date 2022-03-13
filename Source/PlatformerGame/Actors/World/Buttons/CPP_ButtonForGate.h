// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BaseButton.h"
#include "CPP_ButtonForGate.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_ButtonForGate : public ACPP_BaseButton
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Button's Variables")
	TArray<class ACPP_BaseGate*> GatesToHandle;
protected:
	virtual void ImplementsButton() override;
};
