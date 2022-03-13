// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/CPP_BaseWorldActor.h>
#include "CPP_BaseGate.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_BaseGate : public ACPP_BaseWorldActor
{
	GENERATED_BODY()
protected:
	virtual void ImplementsGate();
	UFUNCTION(BlueprintImplementableEvent)
	void PlayGateAnimation();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gate's Variables")
	bool Open = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gate's Variables")
	bool AnimationgPlaying = false;
public:
	friend class ACPP_ButtonForGate;
};
