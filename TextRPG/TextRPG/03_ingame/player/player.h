#pragma once
#include <iostream>
#include <string>
#include "../../03_ingame/inventory.h" 

using namespace std;

class Player
{
public:
	Player() : hp(200), level(1), attack(30), exp(0), maxHp(200)
	{
		inventory = new Inventory();
	}
	~Player() 
	{
		delete inventory;
	}

	void SetHp(int hp);
	int GetHp();

	void SetMaxHp(int maxHp);
	int GetMaxHp();

	void SetName(string name);
	string GetName();

	void SetLevel(int level);
	int GetLevel();

	void SetAttack(int attack);
	int GetAttack();

	void SetExp(int exp);
	int GetExp();

	Inventory* GetInventory(); 
	void UseItem();

	void LevelUp();
	bool CanLevelUp() const;

	void GainExp(int expAmount);

private:
	int hp;
	int maxHp;
	string name;
	int level;
	int attack;
	int exp;
	Inventory* inventory; 

};