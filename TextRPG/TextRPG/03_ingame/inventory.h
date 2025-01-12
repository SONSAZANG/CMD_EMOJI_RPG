#pragma once
#include <vector>
#include "../01_core/item_base.h"

class Inventory
{
public:
	Inventory() 
	{
		gold = 0;
	}

	int GetGold() const
	{
		return gold ;
	}
	void SetGold(int gold) {
		this->gold = gold;
	}

	bool IsInventoryEmpty() const
	{
		return inventory.empty();
	}

	Item* GetInventoryItem (int index);
	void DisplayInventory ();
	void DisplayGoldInfo();

	void AddToInventory(Item* item);
	void DeleteFromInventory(int index);

private:
	int gold;
	vector<Item*> inventory;
};
