#pragma once

#include "../01_core/singleton_base.h"
#include "../02_manager/player_manager.h"
#include "../02_manager/shop_manager.h"
#include "../02_manager/monster_manager.h"
#include "../02_manager/scene_manager.h"
#include "../02_manager/job_manager.h"
#include <iostream>

using namespace std;
class GameManager : public SingletonBase<GameManager>
{
public:
	void CreatePlayerBase();
	void Clear();
	void Init();

	void Test();

private:
	bool IsPlaying;
};