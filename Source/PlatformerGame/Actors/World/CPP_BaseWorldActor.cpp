// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseWorldActor.h"
#include "Kismet/KismetMaterialLibrary.h"

ACPP_BaseWorldActor::ACPP_BaseWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetActorTickEnabled(false);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));

	if (Mesh)
	{
		Mesh->SetupAttachment(Root);
		Mesh->SetMobility(EComponentMobility::Movable);
	}
}
void ACPP_BaseWorldActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_BaseWorldActor::SetMeshMaterialColor(UMaterialInstanceDynamic* MaterialInstance, UStaticMeshComponent* StaticMesh)
{
	MaterialInstance->SetVectorParameterValue(FName("PColor"), MeshColor);
	StaticMesh->SetMaterial(0, MaterialInstance);
}
