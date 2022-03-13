// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/CPP_BaseWorldActor.h>
#include "CPP_BaseButton.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_BaseButton : public ACPP_BaseWorldActor
{
	GENERATED_BODY()
public:
	ACPP_BaseButton();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button's Components")
	UAudioComponent* Audio;
public:
	virtual void Interact_Implementation(class ACPP_PlayerCharacter* Caller) override;
protected:
	virtual void ImplementsButton() {}
	UFUNCTION(BlueprintImplementableEvent)
	void PlayButtonAnimation();
	virtual void PlayWorldActorSound() override;
};
