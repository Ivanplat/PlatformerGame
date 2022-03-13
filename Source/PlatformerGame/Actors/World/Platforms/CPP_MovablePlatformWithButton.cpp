#include "CPP_MovablePlatformWithButton.h"
#include <PlatformerGame/Actors/World/Buttons/CPP_ButtonForPlatform.h>

ACPP_MovablePlatformWithButton::ACPP_MovablePlatformWithButton()
{
	ChildButton = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildButton"));
	ChildButton->SetupAttachment(MovingSpace);
}

void ACPP_MovablePlatformWithButton::BeginPlay()
{
	Super::BeginPlay();
	if (ChildButton->GetClass())
	{
		if (auto Button = Cast<ACPP_ButtonForPlatform>(ChildButton->GetChildActor()))
		{
			Button->PlatformsToHandle.Add(this);
		}
	}
}
