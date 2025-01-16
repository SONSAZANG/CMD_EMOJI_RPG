#pragma once
#include "../01_core/singleton_base.h"
#include "Monsters.h"
#include <iostream>

class BattleManager : public SingletonBase<BattleManager>
{
public:	
	void Excute(Monster& monster);
	bool GetIsWin() const;
	void SelectionBehavior(Monster& monster); // 던전씬 접근
	void AttackTarget(const bool& playerFlag, Monster& monster);
	void GetVictoryReWard();
	void SelectionItem(Monster& monster);
	
private:
	bool isWin;
};