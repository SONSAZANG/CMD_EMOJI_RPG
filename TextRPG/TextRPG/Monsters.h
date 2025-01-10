#pragma once
#include "MonsterSpawnManager.h"
#include <stdlib.h>
#include "Monsters.h"

//MonsterSpawnmanager
//- MonsterSpawnRandom
//-- Monster A, B, C ( name, hp, atk, exp ) ( hp = player(lvl x 20 ~ lvl x 30) ) ( atk = player(lvl x 5 ~ lvl x 10) )
//-- Boss Monster ( name, hp, atk, exp ) (hp = (A,B,C)hp * 50, atk = (A,B,C)atk * 50)


// --------- Monster Type here -------------

enum MonsterType
{
	MT_GOBLIN = 1,
	MT_ORC = 2,
	MT_TROLL = 3,
	MT_BOSSMONSTER = 4,
};

class Monsters : public MonsterSpawnManager
{
public:
	Monsters(int type);
	void SetStats(int playerlevel); // TODO : Create Monster Status

protected:
	int _monsterType;
};

class Goblin : public Monsters
{
public:
	Goblin(int playerlevel) : Monsters(MT_GOBLIN) { SetStats(playerlevel); }
};

class Orc : public Monsters
{
public:
	Orc(int playerlevel) : Monsters(MT_ORC) { SetStats(playerlevel); }
};

class Troll : public Monsters
{
public:
	Troll(int playerlevel) : Monsters(MT_TROLL) { SetStats(playerlevel); }
};

class BoosMonster : public Monsters
{
public:
	BoosMonster(MonsterSpawnManager* goblin, MonsterSpawnManager* orc, MonsterSpawnManager* troll)
		: Monsters(MT_BOSSMONSTER)
	{
		MonsterSpawnManager* randMonster = nullptr;
		int choice = rand() % 3;
		if (choice == 0)
			randMonster = goblin;
		else if (choice == 1)
			randMonster = orc;
		else
			randMonster = troll;

		_hp = randMonster->GetHp() * 50;
		_attack = randMonster->GetAttack() * 50;
	}
};

