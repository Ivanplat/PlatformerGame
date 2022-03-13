// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_BaseButton.h"
#include "CPP_ButtonForEBox.generated.h"

UCLASS()
class PLATFORMERGAME_API ACPP_ButtonForEBox : public ACPP_BaseButton
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button's Variables")
	TArray<class ACPP_BaseEBox*> EBoxesToImplement;
protected:
	virtual void ImplementsButton() override;
};
