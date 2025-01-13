#include "player.h"
#include "../Job.h"

constexpr int MAX_LEVEL = 10;
constexpr int EXP_FOR_LEVEL_UP = 100;

void Player::SetHp(int hp)
{
	if (hp >= 0 && hp <= maxHp)
	{
		this->hp = hp;
	}
}

void Player::SetMaxHp(int maxHp)
{
	if (maxHp > 0)
	{
		this->maxHp = maxHp;
	}
}

void Player::SetName(string name)
{
	this->name = name;
}

void Player::SetLevel(int level)
{
	if (level > 0 && level <= MAX_LEVEL)
	{
		this->level = level;
	}
}

void Player::SetAttack(int attack)
{
	if (attack > 0)
	{
		this->attack = attack;
	}
}

void Player::SetExp(int exp)
{
	if (exp >= 0)
	{
		this->exp = exp;
	}
}

void Player::SetJob(const string& job)
{
	this->job = job;
	isJobChosen = true;
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
		if (level == 5 && !isJobChosen)
		{
			jobs.ChooseJob(this);
		}

		if (level >= MAX_LEVEL)
		{
			exp = 0;
			level = MAX_LEVEL;
			break;
		}

		level++;
		exp -= EXP_FOR_LEVEL_UP;

		maxHp += level * 20;
		attack += level * 5;
	}

	if (initialLevel != level)
	{
		hp = maxHp;
		UpdateTitle();
		cout << "���� ��! ���� ����: " << level
			<< "\n" << GetName()
			<< "\nü��: " << hp
			<< "\n�ִ� ü��: " << maxHp
			<< "\n���ݷ�: " << attack
			<< "\n����ġ: " << exp << endl;
	}
}

bool Player::CanLevelUp() const
{
	return exp >= EXP_FOR_LEVEL_UP && level < MAX_LEVEL;
}

void Player::GainExp(int expAmount)
{
	exp += expAmount;
	cout << "����ġ " << expAmount << " ȹ��! ���� ����ġ: " << exp << endl;
	LevelUp();
}

void Player::UpdateTitle()
{
	if (isJobChosen)
	{
		title = job;
	}
	else if (level >= 1 && level <= titles.size())
	{
		title = titles[level - 1];
	}
}