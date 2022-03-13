// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_PlayerController.generated.h"

DECLARE_DELEGATE(FPlayerSpawned);
DECLARE_DELEGATE_OneParam(FPlayerReachedEnd, class ACPP_PlayerController*);
DECLARE_DELEGATE_OneParam(FPlayerDead, class ACPP_PlayerController*);

UCLASS()
class PLATFORMERGAME_API ACPP_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ACPP_PlayerController();
protected:
	virtual void BeginPlay() override;
public:
	FPlayerSpawned PlayerSpawnedDelegate;
	FPlayerDead PlayerDeadDelegate;
	FPlayerReachedEnd PlayerReachedEnd;
protected:
	UFUNCTION()
	virtual void OnPlayerSpawned();
	UFUNCTION()
	virtual void OnPlayerReachedEnd(ACPP_PlayerController* PlayerController);
	UFUNCTION()
	virtual void OnEndGame();
};
