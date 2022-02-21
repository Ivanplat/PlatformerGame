#include "CPP_BasePlatform.h"

ACPP_BasePlatform::ACPP_BasePlatform()
{
	PrimaryActorTick.bCanEverTick = false;
	SetActorTickEnabled(false);
	bStaticMeshReplicateMovement = true;

	if (auto StaticMesh = GetStaticMeshComponent())
	{
		StaticMesh->SetMobility(EComponentMobility::Movable);
	}
}
