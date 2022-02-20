// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_DataActor.generated.h"


USTRUCT(BlueprintType)
struct FS_DamageInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Info Struct")
	class ACPP_PlayerState* InstigatorPlayerState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Info Struct")
	UObject* InstigatorObject;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Info Struct")
	int32 Damage;
};

UCLASS()
class PLATFORMERGAME_API ACPP_DataActor : public AActor
{
	GENERATED_BODY()
	
};
