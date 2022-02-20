// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_BasePlatform.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_BasePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_BasePlatform();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Platform Components")
	class USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Components")
	class UStaticMeshComponent* StaticMesh;
};
