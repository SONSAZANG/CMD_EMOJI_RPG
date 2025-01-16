#pragma once
#include "../../01_core/item_base.h"
#include "../player/player.h"

class HealthPotion : public Item 
{
public:
	HealthPotion(int amount = 20, float multiple = 0.5) 
	{
		name = "HealthPotion" + to_string(amount);
		description = "체력을 " + to_string(amount);
		description += " 회복시킵니다.";
		healthRestore = amount;
		price = (int)(amount * multiple);
		itemType = ITEM_Potion;
	}

	string GetName() const 
	{ 
		return name; 
	}
	int GetAmount() const 
	{ 
		return healthRestore; 
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

	~HealthPotion() {}

private:
	string name;
	string description;
	ItemType itemType;
	int healthRestore;
	int price;
	
};
