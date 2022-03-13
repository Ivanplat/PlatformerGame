// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseDamagableObstacle.h"
#include "Components/BoxComponent.h"
#include <PlatformerGame/Player/CPP_PlayerCharacter.h>

ACPP_BaseDamagableObstacle::ACPP_BaseDamagableObstacle()
{
	HitCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HitCollision"));
	HitCollision->SetupAttachment(Root);
	HitCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_BaseDamagableObstacle::OnCollisionOverlaped);
}

void ACPP_BaseDamagableObstacle::OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACPP_PlayerCharacter* PlayerCharacter = Cast<ACPP_PlayerCharacter>(OtherActor))
	{
		GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, this, &ACPP_BaseDamagableObstacle::MakeDamage, DamageTimeDelay, true, DamageTimeDelay);
	}
}

void ACPP_BaseDamagableObstacle::MakeDamage()
{
	TSubclassOf<ACPP_PlayerCharacter> ClassToFind;
	TArray<AActor*> OutActors;
	HitCollision->GetOverlappingActors(OutActors, ClassToFind);
	if (OutActors.Num() > 0)
	{
		if (ACPP_PlayerCharacter* PlayerCharacter = Cast<ACPP_PlayerCharacter>(OutActors[0]))
		{
			FS_DamageInfo DI;
			DI.Damage = 5;
			DI.InstigatorObject = this;
			DI.InstigatorPlayerState = nullptr;
			PlayerCharacter->HealthComponent->MakeDamageAdvanced(DI);
		}
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(DamageTimerHandle);
		if (DamageTimerHandle.IsValid())
		{
			DamageTimerHandle.Invalidate();
		}
	}
}
