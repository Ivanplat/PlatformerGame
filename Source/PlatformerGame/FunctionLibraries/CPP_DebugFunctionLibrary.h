// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_DebugFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API UCPP_DebugFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Debug Library")
	static void PrintDebugW(FString Text, UObject* WorldContext);
};
