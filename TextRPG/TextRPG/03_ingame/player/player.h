#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../../03_ingame/inventory.h" 

using namespace std;

class Player
{
public:
	Player() : hp(200), level(1), attack(30), exp(0), maxHp(200), title("초심자")
	{
		inventory = new Inventory();
	}
	~Player() 
	{
		delete inventory;
	}

	void SetHp(int hp);
	int GetHp() const { return hp; }

	void SetMaxHp(int maxHp);
	int GetMaxHp() const { return maxHp; }

	void SetName(string name);
	string GetName() const { return "[" + title + "] " + name; }

	void SetLevel(int level);
	int GetLevel() const { return level; }

	void SetAttack(int attack);
	int GetAttack() const { return attack; }

	void SetExp(int exp);
	int GetExp() const { return exp; }

	Inventory* GetInventory(); 
	void UseItem();

	void LevelUp();
	bool CanLevelUp() const;

	void GainExp(int expAmount);

	void UpdateTitle();
	void ChooseJob();

private:
	int hp;
	int maxHp;
	string name;
	int level;
	int attack;
	int exp;
	string title;
	vector<string> titles = {"초심자", "모험가", "견습생", "도전자"};
	string job;
	bool isJobChosen = false;
	Inventory* inventory; 

};