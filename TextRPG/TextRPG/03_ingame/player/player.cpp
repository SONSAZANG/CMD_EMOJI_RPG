#include "player.h"

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
			ChooseJob();
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
		cout << "레벨 업! 현재 레벨: " << level
			<< "\n" << GetName()
			<< "\n체력: " << hp
			<< "\n최대 체력: " << maxHp
			<< "\n공격력: " << attack
			<< "\n경험치: " << exp << endl;
	}
}

bool Player::CanLevelUp() const
{
	return exp >= EXP_FOR_LEVEL_UP && level < MAX_LEVEL;
}

void Player::GainExp(int expAmount)
{
	exp += expAmount;
	cout << "경험치 " << expAmount << " 획득! 현재 경험치: " << exp << endl;
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

void Player::ChooseJob()
{
	cout << "레벨 5에 도달해서 전직할 수 있습니다.\n";
	cout << "1. 전사\n2. 궁수\n3. 어쌔신\n";
	string input;
	int choice;
	while (true)
	{
		cout << "전직할 직업을 선택하세요(1-3): ";
		getline(cin, input);

		try
		{
			choice = stoi(input);

			if (choice >= 1 && choice <= 3)
			{
				switch (choice)
				{
				case 1: job = "전사"; break;
				case 2: job = "궁수"; break;
				case 3: job = "어쌔신"; break;
				}
				break;
			}
			else
			{
				cout << "잘못된 입력입니다. 1-3 사이의 숫자를 입력해주세요.\n";
			}
		}
		// 숫자로 변환할 수 없는 문자열이 입력된 경우
		catch (invalid_argument& e)
		{
			cout << "잘못된 입력입니다. 1-3 사이의 숫자를 입력해주세요.\n";
		}
		// 입력한 숫자가 너무 큰 경우
		catch (out_of_range& e)
		{
			cout << "입력한 숫자가 너무 큽니다. 1-3 사이의 숫자를 입력해주세요.\n";
		}
	}
	isJobChosen = true;
	cout << "축하합니다! '" << job << "'로 전직했습니다!" << endl;
}



