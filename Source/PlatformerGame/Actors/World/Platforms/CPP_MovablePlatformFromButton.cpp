// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MovablePlatformFromButton.h"
#include <PlatformerGame/Actors/World/Buttons/CPP_ButtonForPlatform.h>

ACPP_MovablePlatformFromButton::ACPP_MovablePlatformFromButton()
{
	MoveFromStart = false;
}

void ACPP_MovablePlatformFromButton::ImplementsPlatform()
{
	if (TimelineFloatCurve && TimelineComponent)
	{
		TimelineComponent->IsPlaying() ? TimelineComponent->Stop() : TimelineComponent->Play();
	}
}
