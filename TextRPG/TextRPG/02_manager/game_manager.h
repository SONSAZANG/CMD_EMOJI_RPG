#pragma once

#include "../01_core/singleton_base.h"
#include "../02_manager/player_manager.h"
#include "../02_manager/shop_manager.h"
#include "../02_manager/Monster_Spawn_Manager.h"
#include <iostream>
using namespace std;
class GameManager : public SingletonBase<GameManager>
{
public:
	void Loading();
	void Run();
	void CreatePlayerBase();
	void SpawnRandomMonster();
	void Battle();
	void VisitShop();
	void Exit();

private:
	bool IsPlaying;
	PlayerManager* playerManager;
	ShopManager* shopManager;
};