// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ButtonForGate.h"
#include "CPP_ButtonForGateDepends.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API ACPP_ButtonForGateDepends : public ACPP_ButtonForGate
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button's Variables")
	TArray<class ACPP_BaseEBox*> Eboxes;
protected:
	virtual void ImplementsButton() override;
	virtual bool CheckEboxes() const;
};
