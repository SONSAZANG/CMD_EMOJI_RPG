#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player() : hp(200), level(1), attack(30), exp(0) {}

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

private:
	int hp;
	string name;
	int level;
	int attack;
	int exp;
};