// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/Zones/CPP_BaseZone.h>
#include "CPP_EndZone.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_EndZone : public ACPP_BaseZone
{
	GENERATED_BODY()
protected:
	virtual void OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
										  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
