// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MovablePlatform.h"
#include "Components/SplineComponent.h"
#include "PlatformerGame/FunctionLibraries/CPP_DebugFunctionLibrary.h"

ACPP_MovablePlatform::ACPP_MovablePlatform()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineComponent"));
	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	RootComponent = Root;
	Spline->SetupAttachment(Root);
	GetStaticMeshComponent()->SetupAttachment(Root);

	TimelineInterp.BindUFunction(this, FName("OnTimelineInterp"));
	TimelineEnd.BindUFunction(this, FName("OnTimelineEnd"));
}

void ACPP_MovablePlatform::BeginPlay()
{
	Super::BeginPlay();


	if (TimelineFloatCurve && TimelineComponent)
	{
		TimelineComponent->AddInterpFloat(TimelineFloatCurve, TimelineInterp);
		TimelineComponent->SetTimelineFinishedFunc(TimelineEnd);
		TimelineComponent->Play();
	}
}

void ACPP_MovablePlatform::OnTimelineInterp(float Value)
{
	float SplineLengh = Spline->GetSplineLength();
	float Distance = Value * SplineLengh;
	FVector NewWorldLocation = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	FRotator NewRelativeRotation = Spline->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	FHitResult HitResult;
	GetStaticMeshComponent()->SetWorldLocation(NewWorldLocation);
	GetStaticMeshComponent()->SetRelativeRotation(NewRelativeRotation);
}

void ACPP_MovablePlatform::OnTimelineEnd()
{
	Played = !Played;
	Played ? TimelineComponent->Reverse() : TimelineComponent->Play();
}
