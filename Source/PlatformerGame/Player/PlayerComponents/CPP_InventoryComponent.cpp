#include "CPP_InventoryComponent.h"
#include "Net/UnrealNetwork.h"
#include <PlatformerGame/Actors/Items/CPP_BaseItem.h>
#include <PlatformerGame/Player/CPP_PlayerCharacter.h>
#include <PlatformerGame/Player/CPP_PlayerController.h>
#include <PlatformerGame/UI/CPP_PlayerHUD.h>

UCPP_InventoryComponent::UCPP_InventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SelectedItem = nullptr;
	SetComponentTickEnabled(false);
	CreateInventory();
}


void UCPP_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCPP_InventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCPP_InventoryComponent, Inventory);
	DOREPLIFETIME(UCPP_InventoryComponent, SelectedItem);
}

void UCPP_InventoryComponent::CreateInventory()
{
	for (int i = 0; i < InventorySize; i++)
	{
		auto temp = FS_ItemInfo();
		temp.ItemIndex = i;
		Inventory.Add(temp);
	}
}

const int32 UCPP_InventoryComponent::FindEmptyItemIndexSlot()
{
	int32 result = -1;
	Inventory.Find(FS_ItemInfo(), result);
	return result;
}

const int32 UCPP_InventoryComponent::FindSameItemIndexSlot(FS_ItemInfo& ItemInfo)
{
	int32 result = -1;
	Inventory.Find(ItemInfo, result);
	return result;
}

const int32 UCPP_InventoryComponent::FindSameItemIndexSlot(FS_ItemInfo& ItemInfo, int32 StartingIndex)
{
	return int32();
}

TArray<int32> UCPP_InventoryComponent::FindAllSameItemIndexSlots(FS_ItemInfo& ItemInfo)
{
	TArray<int32> result;
	for (const auto& Item : Inventory)
	{
		if (Item.ItemClass == ItemInfo.ItemClass)
		{
			result.Add(Item.ItemIndex);
		}
	}
	return result;
}

const bool UCPP_InventoryComponent::AddToEmptySlot(FS_ItemInfo& ItemInfo)
{
	auto EmptySlotIndex = FindEmptyItemIndexSlot();
	if (EmptySlotIndex != -1)
	{
		Inventory[EmptySlotIndex] = ItemInfo;
		return true;
	}
	return false;
}

const bool UCPP_InventoryComponent::AddItemToInventory(FS_ItemInfo& ItemInfo, ACPP_BaseItem* ItemActor)
{
	if (ItemInfo.Stackable)
	{
		auto SameIndexes = FindAllSameItemIndexSlots(ItemInfo);
		if (SameIndexes.Num() > 0)
		{
			int32 SumAmount = 0;
			for (const auto& i : SameIndexes)
			{
				SumAmount += Inventory[i].Amount;
			}
			int32 Left = SumAmount % SameIndexes.Num();
			SumAmount -= Left;
			for (const auto& i : SameIndexes)
			{
				if (Inventory[i].Amount != Inventory[i].MaxAmount)
				{
					int32 TempLeft = Inventory[i].MaxAmount - Inventory[i].Amount;
					Inventory[i].Amount = Inventory[i].MaxAmount;
					SumAmount -= TempLeft;
				}
			}
			if (Left != 0)
			{
				ItemInfo.Amount = Left;
				if (!AddToEmptySlot(ItemInfo))
				{
					ItemActor->ItemInfo = ItemInfo;
					return false;
				}
				return true;
			}
		}
		else
		{
			return AddToEmptySlot(ItemInfo);
		}
	}
	else
	{
		return AddToEmptySlot(ItemInfo);
	}
	return false;
}

void UCPP_InventoryComponent::SpawnItem(FS_ItemInfo& ItemInfo)
{
	if (SelectedItem)
	{
		SelectedItem->Destroy();
		SelectedItem = nullptr;
	}
	FActorSpawnParameters Params;
	Params.Owner = GetOwner();
	SelectedItem = GetWorld()->SpawnActor<ACPP_BaseItem>(ItemInfo.ItemClass, Params);
}

void UCPP_InventoryComponent::OnInventoryUpdated()
{
	if (auto PlayerCharacter = GetOwner<ACPP_PlayerCharacter>())
	{
		if (auto PlayerController = PlayerCharacter->GetController<ACPP_PlayerController>())
		{
			if (auto PlayerHUD = PlayerController->GetHUD<ACPP_PlayerHUD>())
			{
				PlayerHUD->UpdateInventoryWidget();
			}
		}
	}
}

void UCPP_InventoryComponent::OnSelectedItemUpdated()
{
}
