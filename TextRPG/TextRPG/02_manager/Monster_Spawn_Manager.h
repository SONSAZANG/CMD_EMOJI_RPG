#pragma once

#include "../01_core/singleton_base.h"
#include "Monsters.h"
#include "player_manager.h"

class MonsterSpawnManager : public SingletonBase<MonsterSpawnManager>
{
public:

    Monster SpawnRandomMonster();
};
