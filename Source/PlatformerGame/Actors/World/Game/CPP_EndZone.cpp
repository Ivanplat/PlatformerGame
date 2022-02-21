// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EndZone.h"
#include "Components/BoxComponent.h"
#include "PlatformerGame/Player/CPP_PlayerCharacter.h"
#include "PlatformerGame/Player/CPP_PlayerController.h"

ACPP_EndZone::ACPP_EndZone()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(Root);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_EndZone::OnBoxCollisionOverlapped);
}

void ACPP_EndZone::OnBoxCollisionOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACPP_PlayerCharacter* PlayerCharacter = Cast<ACPP_PlayerCharacter>(OtherActor))
	{
		if (ACPP_PlayerController* PlayerController = Cast<ACPP_PlayerController>(PlayerCharacter->GetController()))
		{
			PlayerController->PlayerReachedEnd.ExecuteIfBound(PlayerController);
		}
	}
}
