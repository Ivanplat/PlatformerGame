#include "CPP_BaseItem.h"
#include <PlatformerGame/Player/CPP_PlayerCharacter.h>

ACPP_BaseItem::ACPP_BaseItem()
{
}

void ACPP_BaseItem::BeginPlay()
{
	Super::BeginPlay();

	if (auto ItemOwner = Cast<ACPP_PlayerCharacter>(GetOwner()))
	{
		if (auto Mesh = GetSkeletalMeshComponent())
		{
			Mesh->SetSimulatePhysics(false);
			Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			Mesh->AttachToComponent(ItemOwner->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, ItemInfo.AttachingSocketName);
		}
	}
	else
	{
		if (auto Mesh = GetSkeletalMeshComponent())
		{
			Mesh->SetSimulatePhysics(true);
			Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
			Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
		}
	}
}

void ACPP_BaseItem::Interact_Implementation(ACPP_PlayerCharacter* Caller)
{

}
