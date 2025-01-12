#pragma once
#include "../../01_core/item_base.h"
#include "../player/player.h"

class HealthPotion : public Item 
{
public:
	HealthPotion(int amount = 20, float multiple = 0.5) 
	{
		name = "HealthPotion" + to_string(amount);
		healthRestore = amount;
		price = (int)(amount * multiple);
		itemType = ITEM_HealthPotion;
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

	void Use(Player* player) 
	{ 
		player->SetHp(player->GetHp() + healthRestore); 
	}

	~HealthPotion() {}

private:
	string name;
	ItemType itemType;
	int healthRestore;
	int price;
};
