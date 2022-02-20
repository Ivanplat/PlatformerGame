// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacter.h"
#include "Camera/CameraComponent.h"

ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPCamera"));
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPMesh"));
	FPCamera->bUsePawnControlRotation = true;
	FPMesh->SetupAttachment(RootComponent);
	FPCamera->SetupAttachment(FPMesh);

	HealthComponent = CreateDefaultSubobject<UCPP_HealthComponent>(TEXT("HealthComponent"));
	if (HealthComponent)
	{
		HealthComponent->SetIsReplicated(true);
	}
}

void ACPP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ACPP_PlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ACPP_PlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ACPP_PlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ACPP_PlayerCharacter::Turn);

}

void ACPP_PlayerCharacter::MoveForward(float Axis)
{
	FVector Direction = GetActorForwardVector();
	AddMovementInput(Direction, Axis);
}

void ACPP_PlayerCharacter::MoveRight(float Axis)
{
	FVector Direction = GetActorRightVector();
	AddMovementInput(Direction, Axis);
}

void ACPP_PlayerCharacter::LookUp(float Axis)
{
	AddControllerPitchInput(Axis);
}

void ACPP_PlayerCharacter::Turn(float Axis)
{
	AddControllerYawInput(Axis);
}

