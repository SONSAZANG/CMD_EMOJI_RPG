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

		AttackTarget(false, monster);

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
			AttackTarget(true, monster);
		}
		else
		{
			SelectionItem();
			continue;
		}
		break;
	}
}

void BattleManager::AttackTarget(bool playerFlag, Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	auto attackAction = [](const string& attacker, auto& target, auto getAttack, auto getHp, auto setHp) // 람다 함수 정의
	{
		int damage = getAttack();
		int newHp = getHp() - damage;
		newHp = (newHp < 0) ? 0 : newHp;
		setHp(newHp);

		std::cout << attacker << "이 공격합니다." << std::endl;
		std::cout << damage << "의 데미지!!" << std::endl;
		std::cout << target.GetName() << " 남은 체력: " << newHp << std::endl;
	};

	if (playerFlag) // 공격하는 객체와 타겟을 결정하는 flag
	{
		attackAction(player.GetName(), monster,
			[&]() { return player.GetAttack(); },
			[&]() { return monster.GetHp(); },
			[&](int hp) { monster.SetHp(hp); });
	}
	else
	{
		attackAction(monster.GetName(), player,
			[&]() { return monster.GetAttack(); },
			[&]() { return player.GetHp(); },
			[&](int hp) { player.SetHp(hp); });
	}
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