#pragma once

#include "../01_core/singleton_base.h"
#include "Monsters.h"
#include "../03_ingame/boss_monster.h"
#include "player_manager.h"

class MonsterManager : public SingletonBase<MonsterManager>
{
	friend class SingletonBase<MonsterManager>;
private:
	MonsterManager() {};
	~MonsterManager() {};
	
public:
	Monster& GetMonster();
	BossMonster& GetBossMonster();
	void SetMonster(Monster monster);
	void SetMonster(BossMonster monster);
public:
    Monster _monster;
	BossMonster _bossMonster;
};