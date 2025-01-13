#pragma once
#include "../01_core/singleton_base.h"
#include "Monsters.h"
#include <iostream>

class BattleManager : public SingletonBase<BattleManager>
{
public:
	void Excute(Monster& monster);

private:
	void GetVictoryReWard();
	void PlayerActionAttack(Monster& monster);
	void MonsterActionAttack(const Monster& monster);
	void SelectionItem();
	void SelectionBehavior(Monster& monster);
};