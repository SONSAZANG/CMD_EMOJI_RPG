#pragma once

#include "../01_core/singleton_base.h"
#include "../02_manager/MonsterSpawnManager.h"
#include <iostream>
using namespace std;
class GameManager : public SingletonBase<GameManager>
{
public:
	void Loading();
	void Run();
	void CreatePlayer();
	void SpawnMonster();
	void Battle();
	void VisitShop();
	void Exit();

private:
	bool IsPlaying;
	MonsterSpawnManager* _monsterSpawnManager;
	PlayerManager* playerManager;
};