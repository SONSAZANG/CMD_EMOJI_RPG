#pragma once

#include "../../01_core/item_base.h"
#include "../player/player.h"

class AttackBoost : public Item 
{
public:
	AttackBoost(int amount = 10, float multiply = 0.5) 
	{
		attackIncrease = amount;
		price = (int)(amount * multiply);
		name = "AttackBoost" + to_string(amount);
		description = "공격력 +" + to_string(amount);

		itemType = ITEM_Potion;
	}

	string GetName() const 
	{ 
		return name; 
	}
	int GetAmount() const 
	{ 
		return attackIncrease; 
	}
	ItemType GetItemType () const
	{
		return itemType;
	}
	int GetPrice() const 
	{ 
		return price; 
	}

	void Use(Player* player, Monster& monster);

	void GetDescription();


	~AttackBoost() {}

private:
	string name;
	string description;
	ItemType itemType;
	int attackIncrease;
	int price;

};