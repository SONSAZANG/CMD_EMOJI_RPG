#pragma once
#include "../01_core/singleton_base.h"
#include "../03_ingame/shop.h"

class ShopManager : public SingletonBase<ShopManager> {

	friend class SingletonBase<ShopManager>;

private:
	ShopManager() 
	{
		shop = new Shop();
	}
	~ShopManager() 
	{
		delete shop;
	}

public:
	void WelcomShop(Inventory* inventory);
	void BuyItem(Inventory* inventory);
	void SellItem(Inventory* inventory);

private:
	Shop* shop;
};