// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerController.h"
#include "CPP_PlayerState.h"
#include "PlatformerGame/FunctionLibraries/CPP_DebugFunctionLibrary.h"
#include "PlatformerGame/Game/CPP_MainGamemode.h"
#include <PlatformerGame/UI/CPP_PlayerHUD.h>

ACPP_PlayerController::ACPP_PlayerController()
{
	PlayerSpawnedDelegate.BindUFunction(this, FName("OnPlayerSpawned"));
}

void ACPP_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ACPP_MainGamemode* Gamemode = Cast<ACPP_MainGamemode>(GetWorld()->GetAuthGameMode()))
	{
		Gamemode->SpawnPlayerDirectly(this);
		Gamemode->GameEndDelegate.BindUFunction(this, FName("OnEndGame"));
	}
}

void ACPP_PlayerController::OnPlayerSpawned()
{
#if defined(__DEBUG)
	UCPP_DebugFunctionLibrary::PrintDebugW("ACPP_PlayerController::OnPlayerSpawned", this);
#endif
	if (ACPP_PlayerHUD* PlayerHUD = Cast<ACPP_PlayerHUD>(GetHUD()))
	{
		if (!PlayerHUD->MainUIWidget)
		{
			PlayerHUD->ShowMainUI();
		}
	}
}

void ACPP_PlayerController::OnPlayerReachedEnd(ACPP_PlayerController* PlayerController)
{
	if (ACPP_PlayerState* PState = GetPlayerState<ACPP_PlayerState>())
	{
		PState->ChangeWinPoints(1);
	}
}

void ACPP_PlayerController::OnEndGame()
{
	if (ACPP_PlayerHUD* PlayerHUD = Cast<ACPP_PlayerHUD>(GetHUD()))
	{
		PlayerHUD->ShowEndWidget();
	}
}
