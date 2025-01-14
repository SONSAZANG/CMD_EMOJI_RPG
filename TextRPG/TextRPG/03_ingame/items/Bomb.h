#pragma once
#include "../../01_core/item_base.h"
#include "../player/player.h"
#include "../../02_manager/Monsters.h"

class Bomb : public Item{
public:
	Bomb(int amount = 100, float multiply = 0.5)
	{
		name = "Bomb";
		attack = amount;
		price = (int)(amount * multiply);

		itemType = ITEM_Attack;
	}

	string GetName() const
	{
		return name;
	}
	int GetAmount() const
	{
		return attack;
	}
	ItemType GetItemType() const
	{
		return itemType;
	}
	int GetPrice() const
	{
		return price;
	}

	void Use(Player* player, Monster& monster);

	~Bomb() {}

private:
	string name;
	ItemType itemType;
	int attack;
	int price;
};