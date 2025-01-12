#pragma once

#include "../../01_core/item_base.h"
#include "../player/player.h"

class AttackBoost : public Item 
{
public:
	AttackBoost(int amount = 10, float multiply = 0.5) 
	{
		name = "AttackBoost" + to_string(amount);
		attackIncrease = amount;
		price = (int)(amount * multiply);

		itemType = ITEM_AttackBoost;
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

	void Use(Player* player)
	{
		player->SetAttack(player->GetAttack() + attackIncrease);
	}

	~AttackBoost() {}

private:
	string name;
	ItemType itemType;
	int attackIncrease;
	int price;

};