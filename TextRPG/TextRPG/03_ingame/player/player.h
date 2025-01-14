#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../../03_ingame/inventory.h" 

using namespace std;

class Player
{
public:
	Player() : hp(200), level(1), attack(30), exp(0), maxHp(200), title(u8"초심자")
	{
		inventory = new Inventory();
	}
	~Player()
	{
		delete inventory;
	}

	void SetHp(const int& hp);
	int GetHp() const { return hp; }

	void SetMaxHp(const int& maxHp);
	int GetMaxHp() const { return maxHp; }

	void SetName(const string& name);
	string GetName() const { return "[" + title + "] " + name; }

	void SetLevel(const int& level);
	int GetLevel() const { return level; }

	void SetAttack(const int& attack);
	int GetAttack() const { return attack; }

	void SetExp(const int& exp);
	int GetExp() const { return exp; }

	void SetJob(const string& job);
	string GetJob() const { return job; }

	Inventory* GetInventory(); 
	void UseItem();

	void LevelUp();
	bool CanLevelUp() const;

	void GainExp(int expAmount);

	void UpdateTitle();

	bool IsDead();

private:
	int hp;
	int maxHp;
	string name;
	int level;
	int attack;
	int exp;

	string title;
	vector<string> titles = { u8"초심자", u8"모험가", u8"견습생", u8"도전자" };

	string job;
	bool isJobChosen = false;

	bool isDead = false;

	Inventory* inventory;
};