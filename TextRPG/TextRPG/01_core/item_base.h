#pragma once
#include<string>
#include<iostream>

using namespace std;

class Player;
class Monster;

enum ItemType{
	ITEM_Attack,
	ITEM_Potion,
};

class Item 
{
public:
	virtual std::string GetName() const = 0;
	virtual int GetPrice() const = 0;
	virtual int GetAmount() const = 0;
	virtual ItemType GetItemType () const = 0;
	virtual void Use(Player* player, Monster& monster) = 0;


	virtual ~Item() {}
};
