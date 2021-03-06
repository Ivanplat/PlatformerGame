// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerComponents/CPP_HealthComponent.h"
#include <PlatformerGame/Interfaces/CPP_InteractionInterface.h>
#include "CPP_PlayerCharacter.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_PlayerCharacter : public ACharacter, public ICPP_InteractionInterface
{
	GENERATED_BODY()

public:
	ACPP_PlayerCharacter();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Components")
	class UCameraComponent* FPCamera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Components")
	class USkeletalMeshComponent* FPMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Components")
	UCPP_HealthComponent* HealthComponent;
public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void MoveForward(float Axis);
	virtual void MoveRight(float Axis);
	virtual void LookUp(float Axis);
	virtual void Turn(float Axis);
	virtual void StartJump();
	virtual void StopJump();
	virtual void Interact();
public:
};
