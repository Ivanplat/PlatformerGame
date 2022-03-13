// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPP_PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_PlayerHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void ShowMainUI();
	virtual void ShowEndWidget();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerHUD's Variables")
	TSubclassOf<class UCPP_MainUIWIdget> MainUIWidgetClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerHUD's Variables")
	TSubclassOf<class UCPP_EndGameWidget> EndGameWidgetClass;
protected:
	class UCPP_MainUIWIdget* MainUIWidget;
	class UCPP_EndGameWidget* EndGameWidget;
public:
	friend class ACPP_PlayerController;
};
