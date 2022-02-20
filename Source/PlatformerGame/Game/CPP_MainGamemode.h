// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_MainGamemode.generated.h"


UCLASS()
class PLATFORMERGAME_API ACPP_MainGamemode : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category="Gamemode Player Variables")
	TSubclassOf<class ACPP_PlayerCharacter> PlayerCharacterClassToSpawn;
	UPROPERTY(EditAnywhere, Category = "Gamemode Global Variables")
	bool DebugMode = true;
	UPROPERTY(EditAnywhere, Category = "Gamemode Player Variables")
	TSubclassOf<class ACPP_PlayerStart> PlayerStartClass;
	UPROPERTY(EditAnywhere, Category = "Gamemode Player Variables")
	float TimeToRespawnPlayer = 1.0f;
	UPROPERTY(EditAnywhere, Category = "Gamemode Player Variables")
	bool CanPlayerRespawn = true;
public:
	UFUNCTION()
	virtual void SpawnPlayerDirectly(class ACPP_PlayerController* PlayerController);
	UFUNCTION()
	virtual void KillPlayer(class ACPP_PlayerController* PlayerController);
protected:
	virtual void BeginPlay() override;
	virtual void StartGame();
	virtual class ACPP_PlayerStart* GetFreeSpawnPoint() const;
	virtual void TryToRespawnPlayer(class ACPP_PlayerController* PlayerController, float RespawnTime = 1.0f);
protected:
	UFUNCTION()
	virtual void OnPlayerDead(class ACPP_PlayerController* PlayerController);
};
