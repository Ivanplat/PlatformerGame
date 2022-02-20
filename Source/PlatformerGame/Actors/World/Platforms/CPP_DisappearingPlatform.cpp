// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DisappearingPlatform.h"

void ACPP_DisappearingPlatform::BeginPlay()
{
	GetWorld()->GetTimerManager().SetTimer(PlatformTimerHandle, this, &ACPP_DisappearingPlatform::ShowPlatform, TimeToShow, true, TimeToShow);
}

void ACPP_DisappearingPlatform::ShowPlatform()
{
	if (StaticMesh)
	{
		StaticMesh->GetRelativeScale3D() == FVector(0.0f) ?
		StaticMesh->SetRelativeScale3D(FVector(1.0f)) : StaticMesh->SetRelativeScale3D(FVector(0.0f));
	}
}
