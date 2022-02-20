// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MovablePlatform.h"

ACPP_MovablePlatform::ACPP_MovablePlatform()
{
	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineComponent"));

	TimelineInterp.BindUFunction(this, FName("OnTimelineInterp"));
	TimelineEnd.BindUFunction(this, FName("OnTimelineEnd"));
}

void ACPP_MovablePlatform::BeginPlay()
{
	Super::BeginPlay();


	if (TimelineVectorCurve && TimelineComponent)
	{
		TimelineComponent->AddInterpVector(TimelineVectorCurve, TimelineInterp);
		TimelineComponent->SetTimelineFinishedFunc(TimelineEnd);
		TimelineComponent->Play();
	}
}

void ACPP_MovablePlatform::OnTimelineInterp(FVector InVector)
{
	int32 Mul = Played ? -1 : 1;
	AddActorWorldOffset(InVector * Mul);
}

void ACPP_MovablePlatform::OnTimelineEnd()
{
	Played = !Played;
	Played ? TimelineComponent->Reverse() : TimelineComponent->Play();
}
