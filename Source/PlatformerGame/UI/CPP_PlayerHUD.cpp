// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerHUD.h"
#include <PlatformerGame/Player/CPP_PlayerController.h>
#include <PlatformerGame/UI/Main/CPP_MainUIWIdget.h>

void ACPP_PlayerHUD::ShowMainUI()
{
	if (ACPP_PlayerController* PlayerController = Cast<ACPP_PlayerController>(GetOwner()))
	{
		if (MainUIWidget)
		{
			MainUIWidget->RemoveFromParent();
			MainUIWidget = nullptr;
		}
		else
		{
			PlayerController->SetShowMouseCursor(false);
			MainUIWidget = CreateWidget<UCPP_MainUIWIdget>(PlayerController, MainUIWidgetClass);
			MainUIWidget->AddToViewport();
		}
	}
}