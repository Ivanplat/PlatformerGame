#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <PlatformerGame/Data/CPP_DataActor.h>
#include "CPP_InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLATFORMERGAME_API UCPP_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UCPP_InventoryComponent();
protected:
	virtual void BeginPlay() override;	
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:
	void CreateInventory();
	const int32 FindEmptyItemIndexSlot();
	const int32 FindSameItemIndexSlot(FS_ItemInfo& ItemInfo);
	const int32 FindSameItemIndexSlot(FS_ItemInfo& ItemInfo, int32 StartingIndex);
	TArray<int32> FindAllSameItemIndexSlots(FS_ItemInfo& ItemInfo);
private:
	const bool AddToEmptySlot(FS_ItemInfo& ItemInfo);
public:
	const bool AddItemToInventory(FS_ItemInfo& ItemInfo, class ACPP_BaseItem* ItemActor);
	void SpawnItem(FS_ItemInfo& ItemInfo);
private:
	UFUNCTION()
	void OnInventoryUpdated();
	UFUNCTION()
	void OnSelectedItemUpdated();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Inventory Properties", ReplicatedUsing = OnInventoryUpdated)
	TArray<FS_ItemInfo> Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory Properties", ReplicatedUsing = OnSelectedItemUpdated)
	class ACPP_BaseItem* SelectedItem;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory Properties")
	int32 InventorySize = 5;
};
