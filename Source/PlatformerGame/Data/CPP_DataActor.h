#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_DataActor.generated.h"


USTRUCT(BlueprintType)
struct FS_DamageInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Info Struct")
	class ACPP_PlayerState* InstigatorPlayerState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Info Struct")
	UObject* InstigatorObject;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Info Struct")
	int32 Damage;
};

USTRUCT(BlueprintType)
struct FS_ItemInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	FString ItemName = FString("");
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	FName AttachingSocketName = FName("");
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	int32 Amount = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	int32 MaxAmount = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	bool Stackable = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	UTexture2D* ItemTexture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	int32 ItemIndex = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info Struct")
	TSubclassOf<AActor> ItemClass = nullptr;
public:
	friend const bool operator==(const FS_ItemInfo& left, const FS_ItemInfo& right);
};

UCLASS()
class PLATFORMERGAME_API ACPP_DataActor : public AActor
{
	GENERATED_BODY()
	
};
