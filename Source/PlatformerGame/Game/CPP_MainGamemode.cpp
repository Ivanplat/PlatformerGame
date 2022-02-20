#include "CPP_MainGamemode.h"
#include "PlatformerGame/Player/CPP_PlayerStart.h"
#include "PlatformerGame/Player/CPP_PlayerCharacter.h"
#include "PlatformerGame/Player/CPP_PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


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

ACPP_PlayerStart* ACPP_MainGamemode::GetFreeSpawnPoint() const
{
	TArray<AActor*> FoundActors;
	TArray<ACPP_PlayerStart*> FoundFreeStarts;
	UGameplayStatics::GetAllActorsOfClass(this, PlayerStartClass, FoundActors);	
	for (auto i : FoundActors)
	{
		if (ACPP_PlayerStart* PlayerStart = Cast<ACPP_PlayerStart>(i))
		{
			if (PlayerStart->IsFree())
			{
				FoundFreeStarts.Add(PlayerStart);
			}
		}
	}
	if (FoundFreeStarts.Num() > 0)
	{
		int32 Index = UKismetMathLibrary::RandomIntegerInRange(0, FoundFreeStarts.Num() - 1);
		return FoundFreeStarts[Index];
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
