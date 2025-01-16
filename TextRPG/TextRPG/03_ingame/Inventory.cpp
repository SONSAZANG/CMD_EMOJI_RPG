#include "inventory.h"
#include "../04_Util/gui.h"

void Inventory::UseInventoryItem(Player* player, Monster& monster)
{
	DisplayInventory();

	if (IsInventoryEmpty())
	{
		return;
	}

	UTIL::UPrint("아이템을 사용할 경우 아이템의 번호, 사용하지 않을 경우 0을 입력해주세요.");
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
			UTIL::UPrintEndl("다시 입력하세요.");
			continue;
		};


		inventory[useIndex - 1]->Use(player, monster);
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
	
	if (!IsInventoryEmpty())
	{
		GUI::ClearUI();
		GUI::GoToXY(4, 21);
		uprint("인벤토리 아이템 목록");
		for (int i = 0; i < inventory.size(); ++i)
		{
			GUI::GoToXY(4, 22 + i);
			cout << i + 1 << ". " << inventory[i]->GetName() << endl;

		}
	}
	else
	{
		GUI::GoToXY(4, 22);
		UTIL::UPrintEndl("현재 인벤토리가 비어있습니다!");
	}
}

void Inventory::DisplayGoldInfo()
{
	cout << UTIL::UString("현재 소지 골드: ") << gold << UTIL::UString("골드") << endl;
}

void Inventory::AddToInventory(Item* item)
{
	inventory.push_back(item);
}

void Inventory::DeleteFromInventory(int index)
{
	inventory.erase(inventory.begin() + index);
}

Weapon* Inventory::GetWeapon()
{
	if (equip == nullptr)
		return nullptr;

	return equip.get();
}

void Inventory::UseWeapon()
{
	equip->Use();
}

void Inventory::EquipWeapon(unique_ptr<Weapon> weapon)
{
	equip = move(weapon);
}
