#pragma once
#include "battle_Manager.h"
#include "game_manager.h"
#include "monster_manager.h"
#include "player_manager.h"
#include "../04_Util/util.h"
#include "../04_Util/gui.h"
#include <thread>
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>

bool BattleManager::GetIsWin() const
{
	return !PlayerManager::GetInstance()->GetPlayer().IsDead();
}

void BattleManager::AttackTarget(const bool& playerFlag)
{
	Monster& monster = MonsterManager::GetInstance()->GetMonster();
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
	GUI::DrawBattleHpBox();
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

void BattleManager::SelectionItem()
{
	Monster& monster = MonsterManager::GetInstance()->GetMonster();
	PlayerManager::GetInstance()->GetPlayer().UseItem(monster);
}
