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

void Player::ChooseJob()
{
	cout << "���� 5�� �����ؼ� ������ �� �ֽ��ϴ�.\n";
	cout << "1. ����\n2. �ü�\n3. ��ؽ�\n";
	string input;
	int choice;
	while (true)
	{
		cout << "������ ������ �����ϼ���(1-3): ";
		getline(cin, input);

		try
		{
			choice = stoi(input);

			if (choice >= 1 && choice <= 3)
			{
				switch (choice)
				{
				case 1: job = "����"; break;
				case 2: job = "�ü�"; break;
				case 3: job = "��ؽ�"; break;
				}
				break;
			}
			else
			{
				cout << "�߸��� �Է��Դϴ�. 1-3 ������ ���ڸ� �Է����ּ���.\n";
			}
		}
		// ���ڷ� ��ȯ�� �� ���� ���ڿ��� �Էµ� ���
		catch (invalid_argument& e)
		{
			cout << "�߸��� �Է��Դϴ�. 1-3 ������ ���ڸ� �Է����ּ���.\n";
		}
		// �Է��� ���ڰ� �ʹ� ū ���
		catch (out_of_range& e)
		{
			cout << "�Է��� ���ڰ� �ʹ� Ů�ϴ�. 1-3 ������ ���ڸ� �Է����ּ���.\n";
		}
	}
	isJobChosen = true;
	cout << "�����մϴ�! '" << job << "'�� �����߽��ϴ�!" << endl;
}



