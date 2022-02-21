// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformerGame/Actors/World/CPP_BaseWorldActor.h"
#include "CPP_EndZone.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_EndZone : public ACPP_BaseWorldActor
{
	GENERATED_BODY()
	
public:
	ACPP_EndZone();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "World Actor Component")
	class UBoxComponent* BoxCollision;
protected:
	UFUNCTION()
	virtual void OnBoxCollisionOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
										  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
