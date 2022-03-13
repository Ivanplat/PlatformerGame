// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseEBox.h"
#include <PlatformerGame/Player/CPP_PlayerCharacter.h>
#include <PlatformerGame/Actors/World/Buttons/CPP_ButtonForEBox.h>
#include <PlatformerGame/Actors/World/Buttons/CPP_ButtonForGateDepends.h>
#include "Components/AudioComponent.h"
#include "Components/SpotLightComponent.h"

ACPP_BaseEBox::ACPP_BaseEBox()
{
	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	Audio->SetupAttachment(Root);
	EBoxLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("EBoxLight"));
	EBoxLight->SetupAttachment(Root);
}

void ACPP_BaseEBox::ImplementsEBox()
{
	Enabled = !Enabled;
	SetLightColor();
}

void ACPP_BaseEBox::Interact_Implementation(ACPP_PlayerCharacter* Caller)
{
	if (!PlayingAnimation && CanBeInteracted)
	{
		ImplementsEBox();
		PlayEBoxSound();
		PlayEBoxAnimation();
		ImplementOnOthers();
	}
}

void ACPP_BaseEBox::PlayEBoxSound()
{
	if (Audio->Sound && !Audio->IsPlaying())
	{
		Audio->Play();
	}
}

void ACPP_BaseEBox::ImplementOnOthers()
{
	for (auto i : EboxesToImplement)
	{
		i->ImplementsEBox();
	}
}

void ACPP_BaseEBox::SetLightColor()
{
	if (EBoxLight)
	{
		Enabled ? EBoxLight->SetLightColor(FLinearColor::Green) : EBoxLight->SetLightColor(FLinearColor::Red);
	}
}
