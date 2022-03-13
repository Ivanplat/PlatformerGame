#pragma once

#include "CoreMinimal.h"
#include <PlatformerGame/UI/CPP_BaseWidget.h>
#include "CPP_MainUIWIdget.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERGAME_API UCPP_MainUIWIdget : public UCPP_BaseWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta=(BindWidget))
	class UImage* I_Crosshair;
};
