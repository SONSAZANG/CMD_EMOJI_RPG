#pragma once
#include <iostream>
#include <string>
#include "../../03_ingame/inventory.h" 

using namespace std;

class Player
{
public:
	Player() : hp(200), level(1), attack(30), exp(0) 
	{
		inventory = new Inventory();
	}
	~Player() 
	{
		delete inventory;
	}

	void SetHp(int hp);
	int GetHp();

	void SetName(string name);
	string GetName();

	void SetLevel(int level);
	int GetLevel();

	void SetAttack(int attack);
	int GetAttack();

	void SetExp(int exp);
	int GetExp();

	Inventory* GetInventory(); 
	void UseItem(int index);

private:
	int hp;
	string name;
	int level;
	int attack;
	int exp;
	Inventory* inventory; 

};