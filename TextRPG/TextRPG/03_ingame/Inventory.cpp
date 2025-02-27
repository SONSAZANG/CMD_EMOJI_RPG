﻿#include "inventory.h"
#include "../04_Util/gui.h"

void Inventory::UseInventoryItem(Player* player, Monster& monster)
{
	DisplayInventory();

	if (IsInventoryEmpty())
	{
		return;
	}

	GUI::GoToXY(4, 27);
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

		GUI::ClearUI();
		inventory[useIndex - 1]->Use(player, monster);
		Sleep(2000);
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
	GUI::ClearUI();

	if (!IsInventoryEmpty())
	{
		GUI::GoToXY(4, 21);
		uprint("인벤토리 아이템 목록");
		int j = 0;
		for (int i = 0; i < inventory.size(); ++i)
		{
			if (i!=0 && i % 3 ==0)
				++j;
			GUI::GoToXY(4 + j*25, 22 + (i % 3));
			cout << i + 1 << ". " << inventory[i]->GetName() << endl;
		}
	}
	else
	{
		GUI::GoToXY(4, 22);
		UTIL::UPrintEndl("현재 인벤토리가 비어있습니다!");
		Sleep(2000);
	}
}

void Inventory::DisplayGoldInfo()
{
	GUI::GoToXY(4, 27);
	cout << UTIL::UString("현재 소지 골드: ") << gold << UTIL::UString("골드");
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
	if (equip == nullptr)
		return;
	equip->Use();
}

void Inventory::EquipWeapon(unique_ptr<Weapon> weapon)
{
	equip = move(weapon);
}
