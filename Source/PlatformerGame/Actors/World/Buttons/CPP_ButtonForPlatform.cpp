// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ButtonForPlatform.h"
#include <PlatformerGame/Actors/World/Platforms/CPP_MovablePlatformFromButton.h>
#include <PlatformerGame/Actors/World/Platforms/CPP_MovablePlatformWithButton.h>

void ACPP_ButtonForPlatform::ImplementsButton()
{
	for (auto i : PlatformsToHandle)
	{
		i->ImplementsPlatform();
	}
}