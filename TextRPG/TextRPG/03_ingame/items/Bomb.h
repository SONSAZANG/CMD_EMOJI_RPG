#pragma once
#include "../../01_core/item_base.h"
#include "../player/player.h"
#include "../../02_manager/Monsters.h"

class Bomb : public Item{
public:
	Bomb(int amount = 100, float multiply = 0.5)
	{
		attack = amount;
		price = (int)(amount * multiply);
		name = "Bomb";
		description = "적에게 " + to_string(amount);
		description += "데미지를 입힙니다.";
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

	void GetDescription();

	~Bomb() {}

private:
	string name;
	string description;
	ItemType itemType;
	int attack;
	int price;
};