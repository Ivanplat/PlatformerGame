// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlatformerGame/Data/CPP_DataActor.h"
#include "CPP_HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLATFORMERGAME_API UCPP_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCPP_HealthComponent();
public:
	UPROPERTY(EditAnywhere, Replicated, ReplicatedUsing = OnHealthChanged, Category="Player Variables")
	int32 Health = 100;
protected:
	virtual void BeginPlay() override;
public:	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:
	virtual void MakeDamageAdvanced(FS_DamageInfo& DamageInfo);
protected:
	virtual void KillPlayer();
protected:
	UFUNCTION()
	virtual void OnHealthChanged();
};
