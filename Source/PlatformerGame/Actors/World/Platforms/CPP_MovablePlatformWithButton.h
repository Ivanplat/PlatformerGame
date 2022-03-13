// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MovablePlatformFromButton.h"
#include "CPP_MovablePlatformWithButton.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_MovablePlatformWithButton : public ACPP_MovablePlatformFromButton
{
	GENERATED_BODY()

public:
	ACPP_MovablePlatformWithButton();
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button's Components")
	UChildActorComponent* ChildButton;
};
