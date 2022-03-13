#include "CPP_MainGamemode.h"
#include "PlatformerGame/Player/CPP_PlayerStart.h"
#include "PlatformerGame/Player/CPP_PlayerCharacter.h"
#include "PlatformerGame/Player/CPP_PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include <PlatformerGame/Actors/World/Zones/CPP_SavePointZone.h>

ACPP_MainGamemode::ACPP_MainGamemode()
{
	PlayerHitSavePointDelegate.BindUFunction(this, FName("OnPlayerHitSavePoint"));
}

void ACPP_MainGamemode::SpawnPlayerDirectly(ACPP_PlayerController* PlayerController)
{
	auto PlayerStart = GetFreeSpawnPoint();
	if (PlayerStart)
	{
		FTransform PlayerStartTransform = PlayerStart->GetActorTransform();
		FActorSpawnParameters Params;
		auto PlayerCharacter = GetWorld()->SpawnActor<ACPP_PlayerCharacter>(PlayerCharacterClassToSpawn, PlayerStartTransform, Params);
		if (PlayerCharacter && PlayerController)
		{
			PlayerController->Possess(PlayerCharacter);
			PlayerController->PlayerSpawnedDelegate.ExecuteIfBound();
			PlayerController->PlayerDeadDelegate.BindUFunction(this, FName("OnPlayerDead"), PlayerController);
		}
		else
		{
			TryToRespawnPlayer(PlayerController);
		}
	}
	else
	{
		TryToRespawnPlayer(PlayerController);
	}
}

void ACPP_MainGamemode::KillPlayer(ACPP_PlayerController* PlayerController)
{
	auto PlayerCharacter = PlayerController->GetPawn();
	if (PlayerCharacter)
	{
		PlayerCharacter->Destroy();
	}
	PlayerController->PlayerDeadDelegate.ExecuteIfBound(PlayerController);
}

void ACPP_MainGamemode::BeginPlay()
{
	Super::BeginPlay();


}

void ACPP_MainGamemode::StartGame()
{

}

ACPP_PlayerStart* ACPP_MainGamemode::GetFreeSpawnPoint()
{
	if (!CurrentPlayerSavePoint)
	{
#if defined(__DEBUG)
		UCPP_DebugFunctionLibrary::PrintDebugW("1", this);
#endif
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClassWithTag(this, SavePointsZoneClass, FName("InitSpawn"), FoundActors);
		if (FoundActors.Num() > 0)
		{
#if defined(__DEBUG)
			UCPP_DebugFunctionLibrary::PrintDebugW("2", this);
#endif
			auto P = Cast<ACPP_SavePointZone>(FoundActors[0]);
			CurrentPlayerSavePoint = P;
		}
	}
	TArray<ACPP_PlayerStart*> FoundFreeStarts;
	if (CurrentPlayerSavePoint)
	{
		for (auto PlayerStart : CurrentPlayerSavePoint->PlayerStarts)
		{
			if (PlayerStart->IsFree())
			{
				FoundFreeStarts.Add(PlayerStart);
			}
		}
		if (FoundFreeStarts.Num() > 0)
		{
			int32 Index = UKismetMathLibrary::RandomIntegerInRange(0, FoundFreeStarts.Num() - 1);
			return FoundFreeStarts[Index];
		}
	}
	return nullptr;
}

void ACPP_MainGamemode::TryToRespawnPlayer(ACPP_PlayerController* PlayerController, float RespawnTime)
{
	FTimerHandle TH;
	FTimerDelegate TD;
	TD.BindUFunction(this, FName("SpawnPlayerDirectly"), PlayerController);
	GetWorld()->GetTimerManager().SetTimer(TH, TD, RespawnTime, false, RespawnTime);
}

void ACPP_MainGamemode::OnPlayerDead(ACPP_PlayerController* PlayerController)
{
	if (CanPlayerRespawn)
	{
		TryToRespawnPlayer(PlayerController, TimeToRespawnPlayer);
	}
}

void ACPP_MainGamemode::OnPlayerHitSavePoint(ACPP_SavePointZone* SavePointZone)
{
	CurrentPlayerSavePoint = SavePointZone;
}
