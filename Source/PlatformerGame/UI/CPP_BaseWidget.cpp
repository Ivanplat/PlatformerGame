// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseWidget.h"
#include <PlatformerGame/Player/CPP_PlayerController.h>

void UCPP_BaseWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	PlayerController = GetOwningPlayer<ACPP_PlayerController>();
}