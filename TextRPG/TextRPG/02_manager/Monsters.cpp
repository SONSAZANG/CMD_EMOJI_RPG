#include "Monsters.h"

// Create Monster stats by PlayerLevel

Monsters::Monsters(int type) : MonsterSpawnManager(type)
{
	_monsterType = type;
}

void Monsters::SetStats() // TODO : Load Player level
{
}