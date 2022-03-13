// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_BaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API UCPP_BaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void SynchronizeProperties() override;
protected:
	virtual void CreateWidgetStyle() {}
protected:
	class ACPP_PlayerController* PlayerController;
};
