#include "CPP_MovablePlatformVertical.h"
#include "Kismet/KismetMathLibrary.h"

void ACPP_MovablePlatformVertical::BeginPlay()
{
	Super::BeginPlay();

}

void ACPP_MovablePlatformVertical::OnTimelineInterp(float Value)
{
	auto StartLoc = StartPoint.GetLocation();
	auto StartRot = StartPoint.GetRotation().Rotator();
	auto EndLoc = EndPoint.GetLocation();
	auto EndRot = EndPoint.GetRotation().Rotator();
	auto V = UKismetMathLibrary::VLerp(StartLoc, StartLoc + EndLoc, Value);
	auto R = UKismetMathLibrary::ComposeRotators(StartRot, EndRot);
	auto R1 = UKismetMathLibrary::RLerp(StartRot, R, Value, false);
	MovingSpace->SetRelativeLocationAndRotation(V, R1);
}
