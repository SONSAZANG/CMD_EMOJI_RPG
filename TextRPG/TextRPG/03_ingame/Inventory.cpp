#include "inventory.h"

void Inventory::UseInventoryItem(Player* player)
{
	DisplayInventory();

	if (IsInventoryEmpty()) 
	{
		return;
	}
	cout << u8"아이템을 사용할 경우 아이템의 번호, 사용하지 않을 경우 0을 입력해주세요.";
	while (true)
	{
		int useIndex = 0;
		cin >> useIndex;
		if (useIndex == 0)
			break;

		if (cin.fail() || !(useIndex > 0) || useIndex > inventory.size())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << u8"다시 입력하세요." << endl;
			continue;
		};

		inventory[useIndex - 1]->Use(player);
		DeleteFromInventory(useIndex - 1);

		break;
	}
}


Item* Inventory::GetInventoryItem(int index)
{
	return inventory[index];
}

void Inventory::DisplayInventory() 
{
	cout << u8"소지한 아이템: " << endl;
	if(!IsInventoryEmpty())
	{
		for (int i = 0; i < inventory.size(); ++i)
		{
			cout << i + 1 << ". " << inventory[i]->GetName() << endl;

		}
	}
	else
	{
		cout << u8"현재 인벤토리가 비어있습니다!" << endl;
	}
}

void Inventory::DisplayGoldInfo()
{
	cout << u8"현재 소지 골드: " << gold << u8"골드" << endl;
}

void Inventory::AddToInventory(Item* item)
{
	inventory.push_back(item);
}

void Inventory::DeleteFromInventory(int index)
{
	inventory.erase(inventory.begin() + index);
}


