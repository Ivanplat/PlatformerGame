// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerStart.h"
#include "Components/CapsuleComponent.h"

bool ACPP_PlayerStart::IsFree() const
{
	TArray<AActor*> OverlappingActors;
	GetCapsuleComponent()->GetOverlappingActors(OverlappingActors, PlayerCharacterClass);
	if (OverlappingActors.Num() > 0)
	{
		return false;
	}
	return true;
}
