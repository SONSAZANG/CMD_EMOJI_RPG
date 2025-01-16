#pragma once
#include "inventory.h"
#include "../03_ingame/items/attack_boost.h"
#include "../03_ingame/items/health_potion.h"
#include "../03_ingame/items/Bomb.h"

class Shop {
public:
	Shop() {
		availableItems.push_back(new HealthPotion(20));
		availableItems.push_back(new AttackBoost(10));
		availableItems.push_back(new Bomb());
		availableItems.push_back(new HealthPotion(30));
		availableItems.push_back(new HealthPotion(50));
	}
	~Shop() {
		for (Item* availableItem : availableItems) {
			delete availableItem;
		}
	}

	void DisplayItems();
	vector<Item*> GetItems( ) const { return availableItems; }

	bool CanBuy(int index, Inventory* inventory);
	void BuyItem(int index, Inventory* inventory);
	void SellItem(int index, Inventory* inventory);
	int GetShopItemSize();

private:
	vector<Item*> availableItems;
};