// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ButtonForGate.h"
#include <PlatformerGame/Actors/World/Gates/CPP_BaseGate.h>

void ACPP_ButtonForGate::ImplementsButton()
{
	for (auto i : GatesToHandle)
	{
		i->ImplementsGate();
	}
}
