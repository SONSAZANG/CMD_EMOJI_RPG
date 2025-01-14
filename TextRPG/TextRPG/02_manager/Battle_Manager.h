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
	void AttackTarget(const bool& playerFlag, Monster& monster);
	void SelectionItem();
	void SelectionBehavior(Monster& monster);
};