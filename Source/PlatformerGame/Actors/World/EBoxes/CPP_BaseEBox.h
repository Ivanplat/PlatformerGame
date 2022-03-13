// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/CPP_BaseWorldActor.h>
#include "CPP_BaseEBox.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_BaseEBox : public ACPP_BaseWorldActor
{
	GENERATED_BODY()
public:
	ACPP_BaseEBox();
protected:
	virtual void ImplementsEBox();
	virtual void Interact_Implementation(class ACPP_PlayerCharacter* Caller) override;
	virtual void PlayEBoxSound();
	virtual void ImplementOnOthers();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EBox's Components")
	UAudioComponent* Audio;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EBox's Components")
	class USpotLightComponent* EBoxLight;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EBox's Variables")
	bool Enabled = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EBox's Variables")
	bool PlayingAnimation = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EBox's Variables")
	bool CanBeInteracted = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EBox's Variables")
	TArray<ACPP_BaseEBox*> EboxesToImplement;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayEBoxAnimation();
	UFUNCTION(BlueprintCallable)
	virtual void SetLightColor();
public:
	friend class ACPP_ButtonForEBox;
	friend class ACPP_ButtonForGateDepends;
};
