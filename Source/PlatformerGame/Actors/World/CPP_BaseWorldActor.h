// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <PlatformerGame/Interfaces/CPP_InteractionInterface.h>
#if defined(__DEBUG)
#include <PlatformerGame/FunctionLibraries/CPP_DebugFunctionLibrary.h>
#endif
#include "CPP_BaseWorldActor.generated.h"


UCLASS()
class PLATFORMERGAME_API ACPP_BaseWorldActor : public AActor, public ICPP_InteractionInterface
{
	GENERATED_BODY()
	
public:	
	ACPP_BaseWorldActor();
protected:
	virtual void BeginPlay() override;
protected:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "World Actor Component")
	class USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "World Actor Component")
	class UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "World Actor Varialbes")
	FLinearColor MeshColor;
protected:
	virtual void PlayWorldActorSound() {}
protected:
	UFUNCTION(BlueprintCallable)
	virtual void SetMeshMaterialColor(UMaterialInstanceDynamic* MaterialInstance, UStaticMeshComponent* StaticMesh);
};
