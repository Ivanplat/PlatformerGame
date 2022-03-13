// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#if defined(__DEBUG)
#include "DrawDebugHelpers.h"
#endif

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
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ACPP_PlayerCharacter::StartJump);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Released, this, &ACPP_PlayerCharacter::StopJump);
	PlayerInputComponent->BindAction(FName("Interact"), IE_Pressed, this, &ACPP_PlayerCharacter::Interact);
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

void ACPP_PlayerCharacter::StartJump()
{
	Jump();
}

void ACPP_PlayerCharacter::StopJump()
{
	StopJumping();
}

void ACPP_PlayerCharacter::Interact()
{
	FVector Start;
	FRotator Rotation;
	float Distance = 350.0f;
	GetController()->GetPlayerViewPoint(Start, Rotation);
	FVector End = Start + Rotation.Vector() * Distance;
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

#if defined(__DEBUG)
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 3.0f, 0U, 2U);
#endif

	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility, Params);
	if (HitResult.Actor != nullptr)
	{
		if (auto InteractedActor = HitResult.GetActor())
		{
			if (InteractedActor->Implements<UCPP_InteractionInterface>())
			{
				ICPP_InteractionInterface::Execute_Interact(InteractedActor, this);
			}
		}
	}
}

