#pragma once
#include "battle_Manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "../04_Util/util.h"
#include <thread>
#include <chrono>
#include <random>

void BattleManager::Excute(Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	while (true)
	{
		monster.DisplayMonster();

		SelectionBehavior(monster);

		if (monster.IsDead())
		{
			cout << monster.GetName() << UTIL::UString("사망!\n") << endl;
			break;
		}

		AttackTarget(false, monster);

		if (player.IsDead())
		{
			cout << player.GetName() << UTIL::UString("사망!\n") << endl;
			break;
		}
	}

	uprintendl("전투 종료");

	if (!player.IsDead())
	{
		uprintendl("승리!!");
		GetVictoryReWard();
		isWin = true;
	}
	else
	{
		uprintendl("패배");
		isWin = false;
	}	
}

bool BattleManager::GetIsWin() const
{
	return isWin;
}

void BattleManager::SelectionBehavior(Monster& monster)
{

	while (true) // 인풋 체크를 위한 반복문
	{
		uprintendl("1. 공격		2. 아이템 사용		3. 내 상태 ");
		
		int selectNumber = UTIL::IntegerVerify(selectNumber, 1, 3);

		switch (selectNumber)
		{
		case 1:
			AttackTarget(true, monster);
			break;
		case 2:
			SelectionItem(monster); // 아이템 사용 후 재행동
			continue;
		case 3:
			PlayerManager::GetInstance()->GetPlayerInfo(); // 상태 확인 후 재행동
			continue;
		default:
			cout << u8"정의되지 않은 동작 " << endl;
			break;
		}

		break;
	}
}

void BattleManager::AttackTarget(const bool& playerFlag, Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	auto attackAction = [](const string& attacker, auto& target,
		const auto getAttack, const auto getHp, const auto setHp) // 람다 함수 정의
	{
		int damage = getAttack();
		int newHp = getHp() - damage;
		newHp = (newHp < 0) ? 0 : newHp;
		setHp(newHp);

		cout << attacker << UTIL::UString("이 공격합니다.") << std::endl;
		this_thread::sleep_for(chrono::seconds(1));

		cout << damage << UTIL::UString("의 데미지!!") << std::endl;
		this_thread::sleep_for(chrono::seconds(1));

		cout << target.GetName() << UTIL::UString(" 남은 체력: ") << newHp << std::endl;
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

	int gold = dice(gen); // 10 ~ 20 획득 골드 (과제 요구사항)

	player.GainExp(50); // 경험치 50 고정 획득 (과제 요구사항)
	player.GetInventory()->SetGold(player.GetInventory()->GetGold() + gold);

	player.GetInventory()->DisplayGoldInfo();
}

void BattleManager::SelectionItem(Monster& monster)
{
	PlayerManager::GetInstance()->GetPlayer().UseItem(monster);
}
