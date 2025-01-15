#pragma once
#include "player.h"
#include "../Job.h"
#include "../../04_Util/util.h"

constexpr int MAX_LEVEL = 10;
constexpr int EXP_FOR_LEVEL_UP = 100;

void Player::SetHp(const int& hp)
{
	if (hp >= 0 && hp <= maxHp)
	{
		this->hp = hp;
	}
}

void Player::SetMaxHp(const int& maxHp)
{
	if (maxHp > 0)
	{
		this->maxHp = maxHp;
	}
}

void Player::SetName(const string& name)
{
	this->name = name;
}

void Player::SetLevel(const int& level)
{
	if (level > 0 && level <= MAX_LEVEL)
	{
		this->level = level;
	}
}

void Player::SetAttack(const int& attack)
{
	if (attack > 0)
	{
		this->attack = attack;
	}
}

void Player::SetExp(const int& exp)
{
	if (exp >= 0)
	{
		this->exp = exp;
	}
}

void Player::SetPlayerJob(const string& job)
{
	this->job = job;
	isJobChosen = true;
}

Inventory* Player::GetInventory()
{
	return inventory;
}

void Player::UseItem(Monster& monster)
{	
	inventory->UseInventoryItem(this, monster);
}

void Player::LevelUp()
{
	int initialLevel = level;

	while (CanLevelUp())
	{
		if (level >= MAX_LEVEL)
		{
			level = MAX_LEVEL;
			exp = 0;
			break;
		}

		level++;
		exp -= EXP_FOR_LEVEL_UP;

		maxHp += level * 20;
		attack += level * 5;

		if (level == 5 && !isJobChosen)
		{
			Job jobs;
			jobs.ChooseJob(this);
		}
	}

	if (initialLevel != level)
	{
		hp = maxHp;
		UpdateTitle();
		cout << ustring("레벨 업! 현재 레벨: ") << level << endl;
		cout << ustring(GetName()) << endl;
		cout << ustring("체력: ") << hp << endl; 
		cout << ustring("최대 체력: ") << maxHp << endl;
		cout << ustring("공격력: ") << attack << endl;
		cout << ustring("경험치: ") << exp << endl;
	}
}

bool Player::CanLevelUp() const
{
	return exp >= EXP_FOR_LEVEL_UP && level < MAX_LEVEL;
}

void Player::GainExp(int expAmount)
{
	exp += expAmount;
	cout << ustring("경험치 ") << expAmount << ustring(" 획득! 현재 경험치: ") << exp << endl;

	if (CanLevelUp())
	{
		LevelUp();
	}
}

void Player::UpdateTitle()
{
	if (isJobChosen && level >= 5)
	{
		Job jobs;
		title = jobs.GetJobTitle(job, level);
	}
	else if (level >= 1 && level <= titles.size())
	{
		title = titles[level - 1];
	}
}

bool Player::IsDead()
{
	if (hp <= 0)
	{
		isDead = true;
	}
	else
	{
		isDead = false;
	}
	return isDead;
}

void Player::SetEquipStaus(Weapon* current, Weapon* newWeapon)
{
	if (newWeapon == nullptr)
	{
		hp += current->GetHp();
		attack += current->GetAttack();
	}
	else
	{
		hp = hp - current->GetHp() + newWeapon->GetHp();
		attack = attack - current->GetAttack() + newWeapon->GetAttack();
	}
}