#pragma once
#include "battle_Manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "../04_Util/util.h"
#include "../04_Util/gui.h"
#include <thread>
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>

void BattleManager::Excute(Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	while (true)
	{
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
	return !PlayerManager::GetInstance()->GetPlayer().IsDead();
}

void BattleManager::SelectionBehavior(Monster& monster)
{

	while (true) // 인풋 체크를 위한 반복문
	{
        string questionText1 = ustring("원하는 동작을 입력하세요.");
        string questionText2 = ustring("1. 공격하기 2. 아이템 사용 3. 도망가기");
        string questionText3 = ustring("");
        vector<string> questionTexts = { questionText1, questionText2, questionText3 };
        GUI::DrawQuestionText(questionTexts);

        GUI::GoToXY(8, 27);

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
	string attackText, targetName;
	int damage = 0;
	int hp = 0;

	if (playerFlag)
	{
		// 플레이어가 공격
		monster.SetDamage(player.GetAttack());
	}
	else
	{
		// 몬스터가 공격
		player.SetDamage(monster.GetAttack());
	}

	string atkString = "공격합니다.";
	
	player.GetInventory()->GetWeapon();
	if (player.GetInventory()->GetWeapon() != nullptr)
	{
		atkString = player.GetInventory()->GetWeapon()->GetSoundString();
	}

	attackText = playerFlag ? player.GetName() + "가 " + atkString : monster.GetName() + "가 공격합니다.";
	targetName = playerFlag ? monster.GetName() : player.GetName();
	damage = playerFlag ? player.GetAttack() : monster.GetAttack();
	hp = playerFlag ? monster.GetHp() : player.GetHp();

	GUI::ClearUI();
	string attackText1 = ustring(attackText);
	GUI::DrawBattleHpBox(monster);
	string attackText2 = ustring(to_string(damage) + "의 데미지!!");
	string attackText3 = ustring(targetName + "남은 체력: " + to_string(hp));
	vector<string> attackTexts = { attackText1, attackText2, attackText3 };
	GUI::DrawAttackText(attackTexts);
}

void BattleManager::GetVictoryReWard()
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dice(10, 20);

	int gold = dice(gen); // 10 ~ 20 획득 골드 (과제 요구사항)

	player.GainExp(50); // 경험치 50 고정 획득 (과제 요구사항)
	player.DisplayExpInfo();
	player.DisplayLevelInfo();

	player.GetInventory()->SetGold(player.GetInventory()->GetGold() + gold);

	player.GetInventory()->DisplayGoldInfo();
}

void BattleManager::SelectionItem(Monster& monster)
{
	PlayerManager::GetInstance()->GetPlayer().UseItem(monster);
}
