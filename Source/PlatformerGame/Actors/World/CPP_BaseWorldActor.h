// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_BaseWorldActor.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_BaseWorldActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_BaseWorldActor();
protected:
	virtual void BeginPlay() override;
protected:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "World Actor Component")
	class USceneComponent* Root;
};
