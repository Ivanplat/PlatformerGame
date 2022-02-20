// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerController.h"
#include "CPP_PlayerController.h"
#include "PlatformerGame/FunctionLibraries/CPP_DebugFunctionLibrary.h"
#include "PlatformerGame/Game/CPP_MainGamemode.h"

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
	}
}

void ACPP_PlayerController::OnPlayerSpawned()
{
	UCPP_DebugFunctionLibrary::PrintDebugW("ACPP_PlayerController::OnPlayerSpawned", this);
}
