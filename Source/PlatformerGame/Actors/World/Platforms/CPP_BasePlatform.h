// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/CPP_BaseWorldActor.h>
#include "CPP_BasePlatform.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_BasePlatform : public ACPP_BaseWorldActor
{
	GENERATED_BODY()
	
public:	
	ACPP_BasePlatform();
protected:
	virtual void ImplementsPlatform() {}
};
