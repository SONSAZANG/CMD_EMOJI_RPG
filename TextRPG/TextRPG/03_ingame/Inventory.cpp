#include "inventory.h"

Item* Inventory::GetInventoryItem(int index) 
{
	return inventory[index];
}

void Inventory::DisplayInventory() 
{
	cout << "소지한 아이템: " << endl;
	if(!IsInventoryEmpty())
	{
		for (int i = 0; i < inventory.size(); ++i)
		{
			cout << i + 1 << ". " << inventory[i]->GetName() << endl;

		}
	}
	else
	{
		cout << "현재 인벤토리가 비어있습니다!" << endl;
	}
}

void Inventory::DisplayGoldInfo()
{
	cout << "현재 소지 골드: " << gold << "골드" << endl;
}

void Inventory::AddToInventory(Item* item)
{
	inventory.push_back(item);
}

void Inventory::DeleteFromInventory(int index)
{
	inventory.erase(inventory.begin() + index);
}


