// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BaseObstacle.h"
#include "CPP_BaseDamagableObstacle.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_BaseDamagableObstacle : public ACPP_BaseObstacle
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Obstacle's Components")
	class UBoxComponent* HitCollision;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstacle's Variables")
	float DamageTimeDelay = 1.0f;
public:
	ACPP_BaseDamagableObstacle();
protected:
	UFUNCTION()
	virtual void OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
									  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									  const FHitResult& SweepResult);
protected:
	virtual void MakeDamage();
private:
	FTimerHandle DamageTimerHandle;
};
