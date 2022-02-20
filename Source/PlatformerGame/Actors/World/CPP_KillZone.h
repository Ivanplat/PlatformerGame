#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_KillZone.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_KillZone : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_KillZone();
public:
	USceneComponent* Root;
	class UBoxComponent* BoxCollision;
protected:
	virtual void BeginPlay() override;
protected:
	UFUNCTION()
	virtual void OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
