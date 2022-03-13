// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/CPP_BaseWorldActor.h>
#include "CPP_BaseZone.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_BaseZone : public ACPP_BaseWorldActor
{
	GENERATED_BODY()
public:
	ACPP_BaseZone();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone's Components")
	class UBoxComponent* BoxCollision;
protected:
	UFUNCTION()
	virtual void OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
									  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									  const FHitResult& SweepResult) {}
};
