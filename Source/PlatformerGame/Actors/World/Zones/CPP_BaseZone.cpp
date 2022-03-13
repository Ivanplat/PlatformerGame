// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseZone.h"
#include "Components/BoxComponent.h"

ACPP_BaseZone::ACPP_BaseZone()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(Root);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_BaseZone::OnCollisionOverlaped);
}