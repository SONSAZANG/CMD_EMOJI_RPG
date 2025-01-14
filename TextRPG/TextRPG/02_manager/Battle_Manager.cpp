#pragma once
#include "battle_Manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "../04_Util/input_verify.h"
#include <thread>
#include <chrono>
#include <random>

void BattleManager::Excute(Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	while (true)
	{
		SelectionBehavior(monster);

		if (monster.GetHp() <= 0) // 몬스터 사망 판단
		{
			cout << monster.GetName() << u8" 사망!" << endl;
			break;
		}

		AttackTarget(false, monster);

		if (player.GetHp() <= 0) // 플레이어 사망 판단
		{
			cout << player.GetName() << u8" 사망!" << endl;
			break;
		}
	}

	GetVictoryReWard();
}

void BattleManager::SelectionBehavior(Monster& monster)
{

	while (true) // 인풋 체크를 위한 반복문
	{
		cout << u8"1. 공격	" << u8"2. 아이템 사용 ";
		int selectNumber = 0;
		selectNumber = InputVerify::IntegerVerify(selectNumber, 1, 2);

		if (selectNumber == 1)
		{
			AttackTarget(true, monster);
		}
		else
		{
			SelectionItem(monster);
			//continue;
		}
		break;
	}
}

void BattleManager::AttackTarget(const bool& playerFlag, Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	auto attackAction = [](const string& attacker, auto& target, const auto getAttack, const auto getHp, const auto setHp) // 람다 함수 정의
	{
		int damage = getAttack();
		int newHp = getHp() - damage;
		newHp = (newHp < 0) ? 0 : newHp;
		setHp(newHp);

		cout << attacker << u8"이 공격합니다." << std::endl;
		this_thread::sleep_for(chrono::seconds(1));

		cout << damage << u8"의 데미지!!" << std::endl;
		this_thread::sleep_for(chrono::seconds(1));

		cout << target.GetName() << u8" 남은 체력: " << newHp << std::endl;
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

void BattleManager::SelectionItem(Monster& monster)
{
	PlayerManager::GetInstance()->GetPlayer().UseItem(monster);
}
