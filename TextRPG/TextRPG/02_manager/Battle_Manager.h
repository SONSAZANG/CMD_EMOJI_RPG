#pragma once
#include "../01_core/singleton_base.h"
#include "Monsters.h"
#include <iostream>

class BattleManager : public SingletonBase<BattleManager>
{
public:	
	bool GetIsWin() const;
	void AttackTarget(const bool& playerFlag);
	void GetVictoryReWard();
	void SelectionItem();
	
private:
	bool isWin;
};