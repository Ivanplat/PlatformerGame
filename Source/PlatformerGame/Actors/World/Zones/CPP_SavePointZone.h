// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BaseZone.h"
#include "CPP_SavePointZone.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_SavePointZone : public ACPP_BaseZone
{
	GENERATED_BODY()
protected:
	virtual void OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
									  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									  const FHitResult& SweepResult) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Save Point's Variables")
	TArray<class ACPP_PlayerStart*> PlayerStarts;
public:
	friend class ACPP_MainGamemode;
};
