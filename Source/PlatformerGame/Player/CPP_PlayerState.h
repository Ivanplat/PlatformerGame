// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CPP_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated)
	int32 Points;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated)
	int32 WinPoints;
public:
	virtual void ChangePoints(int32 Value);
	virtual void ChangeWinPoints(int32 Value);
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
