#include "player.h"

constexpr int MAX_LEVEL = 10;
constexpr int EXP_FOR_LEVEL_UP = 100;

void Player::SetHp(int hp)
{
	this->hp = hp;
}

void Player::SetMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}

void Player::SetName(string name)
{
	this->name = name;
}

void Player::SetLevel(int level)
{
	this->level = level;
}

void Player::SetAttack(int attack)
{
	this->attack = attack;
}

void Player::SetExp(int exp)
{
	this->exp = exp;
}

Inventory* Player::GetInventory()
{
	return inventory;
}

void Player::UseItem() 
{	
	inventory->UseInventoryItem(this);
}

void Player::LevelUp()
{
	int initialLevel = level;

	while (CanLevelUp())
	{		
		level++;
		exp -= EXP_FOR_LEVEL_UP;

		maxHp += level * 20;
		attack += level * 5;

		if (level >= MAX_LEVEL)
		{
			exp = 0;
			level = MAX_LEVEL;
			break;
		}
	}

	if (initialLevel != level)
	{
		hp = maxHp;
		UpdateTitle();
		cout << u8"레벨 업! 현재 레벨: " << level
			<< u8"\n" << GetName()
			<< u8"\n체력: " << hp
			<< u8"\n최대 체력: " << maxHp
			<< u8"\n공격력: " << attack
			<< u8"\n경험치: " << exp << endl;
	}
}

bool Player::CanLevelUp() const
{
	return exp >= 100 && level < 10;
}

void Player::GainExp(int expAmount)
{
	exp += expAmount;
	cout << u8"경험치 " << expAmount << u8" 획득! 현재 경험치: " << exp << endl;
	LevelUp();
}

void Player::UpdateTitle()
{
	if (level >= 1)
	{
		title = titles[level - 1];
	}
}



