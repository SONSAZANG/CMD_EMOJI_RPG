#pragma once
#include<string>
#include<iostream>

using namespace std;

class Player;

enum ItemType{
	ITEM_HealthPotion,
	ITEM_AttackBoost,
};

class Item 
{
public:
	virtual std::string GetName() const = 0;
	virtual int GetPrice() const = 0;
	virtual int GetAmount() const = 0;
	virtual ItemType GetItemType () const = 0;
	virtual void Use(Player* player) = 0;


	virtual ~Item() {}
};