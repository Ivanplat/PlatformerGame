// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_SavePointZone.h"
#include <PlatformerGame/Game/CPP_MainGamemode.h>
#include <PlatformerGame/Player/CPP_PlayerCharacter.h>

void ACPP_SavePointZone::OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
											  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
											  const FHitResult& SweepResult)
{
	if (ACPP_PlayerCharacter* PlayerCharacter = Cast<ACPP_PlayerCharacter>(OtherActor))
	{
#if defined(__DEBUG)
		UCPP_DebugFunctionLibrary::PrintDebugW("PLAYER ON SAVE POINT", this);
#endif
		if (ACPP_MainGamemode* Gamemode = Cast<ACPP_MainGamemode>(GetWorld()->GetAuthGameMode()))
		{
			Gamemode->PlayerHitSavePointDelegate.ExecuteIfBound(this);
		}
	}
}

