#include "player.h"

void Player::SetHp(int hp)
{
	this->hp = hp;
}

int Player::GetHp()
{
	return hp;
}

void Player::SetMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}

int Player::GetMaxHp()
{
	return maxHp;
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

void Player::LevelUp()
{
	int initialLevel = level;

	while (CanLevelUp())
	{		
		level++;
		exp -= 100;

		maxHp += level * 20;
		attack += level * 5;

		if (level >= 10)
		{
			exp = 0;
			level = 10;
			break;
		}
	}

	if (initialLevel != level)
	{
		hp = maxHp;

		cout << "���� ��! ���� ����: " << level
			<< "\nü��: " << hp
			<< "\\n�ִ� ü��: " << maxHp
			<< "\n���ݷ�: " << attack
			<< "\n����ġ: " << exp << endl;
	}
}

bool Player::CanLevelUp() const
{
	return exp >= 100 && level < 10;
}

void Player::GainExp(int expAmount)
{
	exp += expAmount;
	cout << "����ġ " << expAmount << " ȹ��! ���� ����ġ: " << exp << endl;
	LevelUp();
}



