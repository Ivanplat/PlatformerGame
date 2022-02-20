// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DebugFunctionLibrary.h"
#include "PlatformerGame/Game/CPP_MainGamemode.h"

void UCPP_DebugFunctionLibrary::PrintDebugW(FString Text, UObject* WorldContext)
{
	if (!WorldContext)
	{
		return;
	}
	if (ACPP_MainGamemode* Gamemode = Cast<ACPP_MainGamemode>(WorldContext->GetWorld()->GetAuthGameMode()))
	{
		if (Gamemode->DebugMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Text);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, Text);
		}
	}
}