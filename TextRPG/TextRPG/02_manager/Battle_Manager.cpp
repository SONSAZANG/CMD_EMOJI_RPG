#pragma once
#include "battle_Manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include <random>

void BattleManager::Excute(Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	while (true)
	{	
		SelectionBehavior(monster);

		if (monster.GetHp() <= 0) // 몬스터 사망 판단
		{
			cout << monster.GetName() << " 사망!" << endl;
			break;
		}

		MonsterActionAttack(monster);

		if (player.GetHp() <= 0) // 플레이어 사망 판단
		{
			cout << player.GetName() << " 사망!" << endl;
			break;
		}
	}

	GetVictoryReWard();
}

void BattleManager::SelectionBehavior(Monster& monster)
{
	while (true) // 인풋 체크를 위한 반복문
	{
		cout << "1. 공격	" << "2. 아이템 사용 ";
		int selectNumber = 0;
		cin >> selectNumber;
		if (cin.fail() || !(selectNumber > 0) || selectNumber > 2) // 예외 처리
		{
			cout << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "다시 입력하세요." << endl;
			continue;
		}

		if (selectNumber == 1)
		{
			PlayerActionAttack(monster);
		}
		else
		{
			SelectionItem();
			continue;
		}
		break;
	}
}

void BattleManager::PlayerActionAttack(Monster& monster) //플레이어가 몬스터를 공격
{	
	Player& player = PlayerManager::GetInstance()->GetPlayer();
	
	cout << player.GetName() << "이 공격합니다." << endl;
	cout << player.GetAttack() << "의 데미지!!" << endl;

	int calculate = monster.GetHp() - player.GetAttack() <= 0 ? 0 : monster.GetHp() - player.GetAttack();

	monster.SetHp(calculate);

	cout << monster.GetName() << " 남은 체력: " << monster.GetHp() << endl;
}

void BattleManager::MonsterActionAttack(const Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	int calculate = player.GetHp() - monster.GetAttack() <= 0 ? 0 : player.GetHp() - monster.GetAttack();

	cout << monster.GetName() << "이 공격합니다." << endl;
	cout << monster.GetAttack() << "의 데미지!!" << endl;

	player.SetHp(calculate);

	cout << player.GetName() << " 남은 체력: " << player.GetHp() << endl;
}

void BattleManager::GetVictoryReWard()
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dice(10, 20);
	
	int gold = dice(gen);

	player.GainExp(50);
	player.GetInventory()->SetGold(player.GetInventory()->GetGold() + gold);

	player.GetInventory()->DisplayGoldInfo();
}

void BattleManager::SelectionItem() // 전투 시스템에 아이템 사용 로직?
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();
	player.GetInventory()->DisplayInventory();

	if (player.GetInventory()->IsInventoryEmpty()) // 인벤토리 비었을 때 빠져나오기
	{
		return;
	}

	while (true)
	{
		int useIndex = 0;
		cout << "사용할 아이템의 번호를 입력해주세요.";
		cin >> useIndex;
		if (cin.fail() || !(useIndex > 0) || useIndex > 2)
		{
			cout << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "다시 입력하세요." << endl;
			continue;
		}

		if (player.GetInventory()->GetInventoryItem(useIndex - 1)->GetItemType() == ITEM_HealthPotion)
		{
			cout << "Hp " << player.GetInventory()->GetInventoryItem(useIndex - 1)->GetAmount() << "를 회복했습니다. ";
			player.UseItem(useIndex - 1);
			cout << "현재 Hp: " << player.GetHp() << endl;
		}
		else
		{
			cout << "Attack " << player.GetInventory()->GetInventoryItem(useIndex - 1)->GetAmount() << "가 증가했습니다. ";
			player.UseItem(useIndex - 1);
			cout << "현재 Attack: " << player.GetAttack() << endl;
		}

		break;
	}
}