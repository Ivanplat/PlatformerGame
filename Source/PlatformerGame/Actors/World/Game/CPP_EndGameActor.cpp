// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EndGameActor.h"
#include <PlatformerGame/Player/CPP_PlayerCharacter.h>
#include <PlatformerGame/Game/CPP_MainGamemode.h>

void ACPP_EndGameActor::Interact_Implementation(ACPP_PlayerCharacter* Caller)
{
	if (auto Gamemode = Cast<ACPP_MainGamemode>(GetWorld()->GetAuthGameMode()))
	{
		Gamemode->GameEndDelegate.ExecuteIfBound();
	}
}