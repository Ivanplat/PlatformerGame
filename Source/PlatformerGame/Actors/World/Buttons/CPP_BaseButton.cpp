#include "CPP_BaseButton.h"
#include <PlatformerGame/Player/CPP_PlayerCharacter.h>
#include "Components/AudioComponent.h"

ACPP_BaseButton::ACPP_BaseButton()
{
	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	Audio->SetupAttachment(Root);
}

void ACPP_BaseButton::Interact_Implementation(ACPP_PlayerCharacter* Caller)
{
#if defined(__DEBUG)
	UCPP_DebugFunctionLibrary::PrintDebugW("INTERACT BUTTON", this);
#endif
	ImplementsButton();
	PlayButtonAnimation();
	PlayWorldActorSound();
}

void ACPP_BaseButton::PlayWorldActorSound()
{
	if (Audio->Sound && !Audio->IsPlaying())
	{
		Audio->Play();
	}
}
