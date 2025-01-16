#pragma once
#include "../01_core/singleton_base.h"
#include "Monsters.h"
#include <iostream>

class BattleManager : public SingletonBase<BattleManager>
{
public:	
	void Excute(Monster& monster);
	bool GetIsWin() const;

	void DisplaySkillAnimation(const string& skillName);
	void BossBattle(Player& player, BossMonster& bossMonster);
	void SelectionBehavior(Monster& monster); // 던전씬 접근
	
private:
	bool isWin;

	void GetVictoryReWard();
	void AttackTarget(const bool& playerFlag, Monster& monster);
	void SelectionItem(Monster& monster);
};