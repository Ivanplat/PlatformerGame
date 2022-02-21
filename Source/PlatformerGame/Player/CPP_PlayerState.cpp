// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerState.h"
#include "Net/UnrealNetwork.h"

void ACPP_PlayerState::ChangePoints(int32 Value)
{
	Points += Value;
}

void ACPP_PlayerState::ChangeWinPoints(int32 Value)
{
	WinPoints += Value;
}

void ACPP_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACPP_PlayerState, Points);
}
