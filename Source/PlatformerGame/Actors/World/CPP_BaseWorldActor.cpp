// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseWorldActor.h"

ACPP_BaseWorldActor::ACPP_BaseWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetActorTickEnabled(false);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}
void ACPP_BaseWorldActor::BeginPlay()
{
	Super::BeginPlay();
	
}
