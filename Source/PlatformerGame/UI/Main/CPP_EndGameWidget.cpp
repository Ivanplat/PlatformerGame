// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EndGameWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include <PlatformerGame/Player/CPP_PlayerController.h>

void UCPP_EndGameWidget::CreateWidgetStyle()
{
	if (B_End)
	{
		B_End->OnPressed.AddDynamic(this, &UCPP_EndGameWidget::OnEndPressed);
	}
}

void UCPP_EndGameWidget::OnEndPressed()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("L_MainMenu"));
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = false;
	}
	RemoveFromParent();
}
