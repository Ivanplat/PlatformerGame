#include "CPP_BasePlatform.h"

ACPP_BasePlatform::ACPP_BasePlatform()
{
	PrimaryActorTick.bCanEverTick = false;
	SetActorTickEnabled(false);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = Root;
	StaticMesh->SetupAttachment(Root);
}
