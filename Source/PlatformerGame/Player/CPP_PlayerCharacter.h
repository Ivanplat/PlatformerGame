// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerComponents/CPP_HealthComponent.h"
#include "CPP_PlayerCharacter.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACPP_PlayerCharacter();
public:
	class UCameraComponent* FPCamera;
	class USkeletalMeshComponent* FPMesh;
	UCPP_HealthComponent* HealthComponent;
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void MoveForward(float Axis);
	virtual void MoveRight(float Axis);
	virtual void LookUp(float Axis);
	virtual void Turn(float Axis);
public:
};
