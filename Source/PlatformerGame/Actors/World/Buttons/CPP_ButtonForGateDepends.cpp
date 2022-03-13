// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ButtonForGateDepends.h"
#include <PlatformerGame/Actors/World/EBoxes/CPP_BaseEBox.h>

void ACPP_ButtonForGateDepends::ImplementsButton()
{
	if (CheckEboxes())
	{
		Super::ImplementsButton();
	}
}

bool ACPP_ButtonForGateDepends::CheckEboxes() const
{
	for (const auto i : Eboxes)
	{
		if (!i->Enabled)
		{
			return false;
		}
	}
	return true;
}
