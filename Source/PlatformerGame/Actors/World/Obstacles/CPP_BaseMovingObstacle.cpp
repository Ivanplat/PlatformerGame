// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseMovingObstacle.h"
#include "Kismet/KismetMathLibrary.h"

ACPP_BaseMovingObstacle::ACPP_BaseMovingObstacle()
{
	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineComponent"));
	MovingSpace = CreateDefaultSubobject<USceneComponent>(TEXT("MovingSpace"));
	MovingSpace->SetupAttachment(Root);
	Mesh->SetupAttachment(MovingSpace);

	TimelineInterp.BindUFunction(this, FName("OnTimelineInterp"));
	TimelineEnd.BindUFunction(this, FName("OnTimelineEnd"));

	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_BaseMovingObstacle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	MovingSpace->AddLocalRotation(ObstacleRotation);
}

void ACPP_BaseMovingObstacle::OnTimelineInterp(float Value)
{
	auto StartLoc = ObstacleStartPoint.GetLocation();
	auto EndLoc = ObstacleEndPoint.GetLocation();
	auto V = UKismetMathLibrary::VLerp(StartLoc, StartLoc + EndLoc, Value);
	MovingSpace->SetRelativeLocation(V);
}

void ACPP_BaseMovingObstacle::OnTimelineEnd()
{
	Played = !Played;
	Played ? TimelineComponent->Reverse() : TimelineComponent->Play();
}

void ACPP_BaseMovingObstacle::MoveObstacle()
{
}

void ACPP_BaseMovingObstacle::BeginPlay()
{
	Super::BeginPlay();
	if (TimelineFloatCurve && TimelineComponent)
	{
		TimelineComponent->AddInterpFloat(TimelineFloatCurve, TimelineInterp);
		TimelineComponent->SetTimelineFinishedFunc(TimelineEnd);
		TimelineComponent->Play();
	}
}
