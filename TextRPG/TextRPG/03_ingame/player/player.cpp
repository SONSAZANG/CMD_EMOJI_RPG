#include "player.h"

void Player::SetHp(int hp)
{
	this->hp = hp;
}

int Player::GetHp()
{
	return hp;
}

void Player::SetName(string name)
{
	this->name = name;
}

string Player::GetName()
{
	return name;
}

void Player::SetLevel(int level)
{
	this->level = level;
}

int Player::GetLevel()
{
	return level;
}

void Player::SetAttack(int attack)
{
	this->attack = attack;
}

int Player::GetAttack()
{
	return attack;
}

void Player::SetExp(int exp)
{
	this->exp = exp;
}

int Player::GetExp()
{
	return exp;
}

Inventory* Player::GetInventory()
{
	return inventory;
}

void Player::UseItem(int index)
{
	inventory->GetInventoryItem(index)->Use(this); 
	inventory->DeleteFromInventory(index);
}



