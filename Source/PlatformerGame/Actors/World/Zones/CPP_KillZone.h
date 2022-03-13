#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/Actors/World/Zones/CPP_BaseZone.h>
#include "CPP_KillZone.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_KillZone : public ACPP_BaseZone
{
	GENERATED_BODY()
	
public:	
	ACPP_KillZone();
protected:
	virtual void BeginPlay() override;
protected:
	virtual void OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
									  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									  const FHitResult& SweepResult) override;
};
