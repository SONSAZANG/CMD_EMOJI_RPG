#pragma once

#include "../01_core/singleton_base.h"
#include "../02_manager/MonsterSpawnManager.h"
#include "../02_manager/player_manager.h"
#include "../02_manager/shop_manager.h"
#include "../02_manager/scene_manager.h"
#include <iostream>
using namespace std;
class GameManager : public SingletonBase<GameManager>
{
public:
	void Loading();
	void Run();
	void CreatePlayerBase();
	void SpawnMonster();
	void Battle();
	void VisitShop();
	void Exit();
	void Init();

private:
	bool IsPlaying;
	MonsterSpawnManager* _monsterSpawnManager;
	PlayerManager* playerManager;
	ShopManager* shopManager;
	SceneManager* sceneManager;
};