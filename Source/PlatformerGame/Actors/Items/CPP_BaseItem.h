#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include <PlatformerGame/Data/CPP_DataActor.h>
#include <PlatformerGame/Interfaces/CPP_InteractionInterface.h>
#include "CPP_BaseItem.generated.h"




UCLASS()
class PLATFORMERGAME_API ACPP_BaseItem : public ASkeletalMeshActor, public ICPP_InteractionInterface
{
	GENERATED_BODY()

public:
	ACPP_BaseItem();
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item's Properties")
	FS_ItemInfo ItemInfo;
protected:
	virtual void Interact_Implementation(class ACPP_PlayerCharacter* Caller) override;
};
