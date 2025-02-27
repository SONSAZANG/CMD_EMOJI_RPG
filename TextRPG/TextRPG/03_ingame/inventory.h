#pragma once
#include <vector>
#include "../01_core/item_base.h"
#include "weapons/weapon.h"
class Mosnter;

class Inventory
{
public:
	Inventory() : gold(0)
	{
		
	}

	int GetGold() const
	{
		return gold ;
	}
	void SetGold(int gold) {
		if (gold < 0)
			this->gold = 0;
		this->gold = gold;
	}

	bool IsInventoryEmpty() const
	{
		return inventory.empty();
	}
	int GetInventorySize() 
	{ 
		return (int)inventory.size(); 
	}

	void UseInventoryItem(Player* player, Monster& monster);

	Item* GetInventoryItem (int index);
	void DisplayInventory ();
	void DisplayGoldInfo();

	void AddToInventory(Item* item);
	void DeleteFromInventory(int index);

	void UseWeapon();
	void EquipWeapon(unique_ptr<Weapon> weapon);
	Weapon* GetWeapon();

private:
	int gold;
	vector<Item*> inventory;
	unique_ptr<Weapon> equip;
};
