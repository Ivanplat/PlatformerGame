// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformerGame/UI/CPP_BaseWidget.h"
#include "CPP_EndGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API UCPP_EndGameWidget : public UCPP_BaseWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	class UButton* B_End;
protected:
	virtual void CreateWidgetStyle() override;
	UFUNCTION()
	virtual void OnEndPressed();
};
