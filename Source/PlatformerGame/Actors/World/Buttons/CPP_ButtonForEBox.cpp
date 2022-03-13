#include "CPP_ButtonForEBox.h"
#include <PlatformerGame/Actors/World/EBoxes/CPP_BaseEBox.h>

void ACPP_ButtonForEBox::ImplementsButton()
{
	for (auto i : EBoxesToImplement)
	{
		i->ImplementsEBox();
	}
}
