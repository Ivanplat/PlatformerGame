// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/CPP_BaseWorldActor.h>
#include "CPP_EndGameActor.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_EndGameActor : public ACPP_BaseWorldActor
{
	GENERATED_BODY()

protected:
	virtual void Interact_Implementation(class ACPP_PlayerCharacter* Caller) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="End Game Actor's Variables")
	TArray<AActor*> ActorsPositions;
	
};
