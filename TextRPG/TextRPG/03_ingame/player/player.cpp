#pragma once
#include "player.h"
#include "../../02_manager/job_manager.h"
#include "../../04_Util/util.h"
#include "../../04_Util/gui.h"
#include "../Scenes/06_job_center_scene.h"
#include "../Scenes/04_town_scene.h"


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

string Player::GetName() const
{
	if (isJobChosen)
	{
		return "[" + title + "] " + name + " (" + job + ")";
	}
	else
	{
		return "[" + title + "] " + name;
	}
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
			cout << ustring("축하합니다! 전직이 가능합니다. 전직소를 방문하세요!") << endl;
		}
	}

	if (initialLevel != level)
	{
		hp = maxHp;
		UpdateTitle();
		//cout << ustring("레벨 업! 현재 레벨: ") << level << endl;
		//cout << ustring(GetName()) << endl;
		//cout << ustring("체력: ") << hp << "/" << maxHp << endl;
		//cout << ustring("공격력: ") << attack << endl;
		//cout << ustring("경험치: ") << exp << endl;
	}
}

bool Player::CanLevelUp() const
{
	return exp >= EXP_FOR_LEVEL_UP && level < MAX_LEVEL;
}

void Player::GainExp(int expAmount)
{
	exp += expAmount;
	//cout << ustring("경험치 ") << expAmount << ustring(" 획득! 현재 경험치: ") << exp << endl;

	if (CanLevelUp())
	{
		LevelUp();
	}
}

void Player::UpdateTitle()
{
	if (level >= 1 && level <= 3)
	{
		title = titles[0];
	}
	else if (level >= 4 && level <= 6)
	{
		title = titles[1];
	}
	else if (level >= 7 && level <= 9)
	{
		title = titles[2];
	}
	else if (level >= 10)
	{
		title = titles[3];
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

void Player::SetEquipStaus()
{
	maxHp = maxHp + inventory->GetWeapon()->GetHp();
	hp = maxHp;

	maxHp = attack + inventory->GetWeapon()->GetAttack();
}

void Player::ChangeJob(string job, string jobName)
{
	GUI::ClearUI();
	GUI::GoToXY(4, 22);
	if (level >= 5 && !isJobChosen)
	{
		SetPlayerJob(job);
		cout << ustring("축하합니다! ") << jobName << "(" << job << ustring(")로 전직했습니다!") << endl;
		ResetGUI();
	}
	else if (level < 5)
	{
		cout << ustring("전직할 수 없습니다. (레벨 5 이상 필요)") << endl;
		ResetGUI();
	}
	else if (isJobChosen)
	{
		cout << ustring("전직할 수 없습니다. (이미 전직 완료)") << endl;
		ResetGUI();
	}
}

void Player::ResetGUI()
{
	GUI::DrawConfirmAsk();
	GUI::ClearUI();
	string questionText1 = ustring("전직소입니다.");
	string questionText2 = ustring("원하는 행동을 입력하세요.");
	string questionText3 = ustring("1. 궁수로 전직 2. 전사로 전직 3. 도적으로 전직 4. 나가기");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);

	GUI::GoToXY(8, 27);
}
