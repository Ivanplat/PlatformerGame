#include "PlatformerGame/Actors/World/CPP_KillZone.h"
#include "Components/BoxComponent.h"
#include "PlatformerGame/Player/CPP_PlayerCharacter.h"
#include "PlatformerGame/FunctionLibraries/CPP_DebugFunctionLibrary.h"

ACPP_KillZone::ACPP_KillZone()
{
	PrimaryActorTick.bCanEverTick = false;
	SetActorTickEnabled(false);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = Root;
	BoxCollision->SetupAttachment(Root);
	BoxCollision->SetBoxExtent(FVector(10000.0f, 10000.0f, 20.0f));
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_KillZone::OnCollisionOverlaped);
}

void ACPP_KillZone::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACPP_KillZone::OnCollisionOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UCPP_DebugFunctionLibrary::PrintDebugW("ACPP_KillZone::OnCollisionOverlaped", GetWorld());
	if (ACPP_PlayerCharacter* PlayerCharacter = Cast<ACPP_PlayerCharacter>(OtherActor))
	{
		FS_DamageInfo DamageInfo;
		DamageInfo.Damage = 1000000;
		DamageInfo.InstigatorPlayerState = nullptr;
		DamageInfo.InstigatorObject = GetWorld();
		PlayerCharacter->HealthComponent->MakeDamageAdvanced(DamageInfo);
	}
}

