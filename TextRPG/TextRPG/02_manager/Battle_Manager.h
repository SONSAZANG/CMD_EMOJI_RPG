#pragma once
#include "../01_core/singleton_base.h"
#include <iostream>

class BattleManager : public SingletonBase<BattleManager>
{
public:
	void Excute();
	void SelectionBehavior();
	void AttackTarget();
	void UseItem();
	void MoveStage() const;
private:
};