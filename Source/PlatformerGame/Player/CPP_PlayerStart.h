// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "CPP_PlayerStart.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_PlayerStart : public APlayerStart
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category="Player Start Variables")
	TSubclassOf<AActor> PlayerCharacterClass;
public:
	virtual bool IsFree() const;
};
