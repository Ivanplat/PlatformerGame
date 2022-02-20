// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_HealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "PlatformerGame/Player/CPP_PlayerCharacter.h"
#include "PlatformerGame/Player/CPP_PlayerController.h"
#include "PlatformerGame/Game/CPP_MainGamemode.h"


UCPP_HealthComponent::UCPP_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetComponentTickEnabled(false);
}

void UCPP_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCPP_HealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCPP_HealthComponent, Health);
}

void UCPP_HealthComponent::MakeDamageAdvanced(FS_DamageInfo& DamageInfo)
{
	if (DamageInfo.InstigatorObject || DamageInfo.InstigatorPlayerState)
	{
		Health -= DamageInfo.Damage;
		if (Health <= 0)
		{
			if (ACPP_PlayerCharacter* PlayerCharacter = Cast<ACPP_PlayerCharacter>(GetOwner()))
			{
				if (ACPP_PlayerController* PlayerController = Cast<ACPP_PlayerController>(PlayerCharacter->GetController()))
				{
					if (ACPP_MainGamemode* Gamemode = Cast<ACPP_MainGamemode>(GetWorld()->GetAuthGameMode()))
					{
						Gamemode->KillPlayer(PlayerController);
					}
				}
			}
		}
	}
}

void UCPP_HealthComponent::KillPlayer()
{

}

void UCPP_HealthComponent::OnHealthChanged()
{
	
}
