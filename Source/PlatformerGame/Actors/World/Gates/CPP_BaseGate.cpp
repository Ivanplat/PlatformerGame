// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseGate.h"
#include <PlatformerGame/Actors/World/Buttons/CPP_ButtonForGate.h>

void ACPP_BaseGate::ImplementsGate()
{
#if defined(__DEBUG)
	UCPP_DebugFunctionLibrary::PrintDebugW("OPENING GATE", this);
#endif
	if (!AnimationgPlaying)
	{
		PlayGateAnimation();
		Open = !Open;
	}
}