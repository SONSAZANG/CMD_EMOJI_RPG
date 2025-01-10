#include "Monsters.h"

// Create Monster stats by PlayerLevel

Monsters::Monsters(int type) : MonsterSpawnManager(type)
{
	_monsterType = type;
}

void Monsters::SetStats(int playerlevel) // TODO : Load Player level
{
	_hp = playerlevel * (rand() % 11 + 20);
	_hp = playerlevel * (rand() % 6 + 5);
	_exp = 50;
}