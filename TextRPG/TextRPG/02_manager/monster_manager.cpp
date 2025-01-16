#include "monster_manager.h"

Monster& MonsterManager::GetMonster()
{
    return _monster;
}

BossMonster& MonsterManager::GetBossMonster()
{
    return _bossMonster;
}

void MonsterManager::SetMonster(Monster monster)
{
    _monster = monster;
}

void MonsterManager::SetMonster(BossMonster monster)
{
    _bossMonster = monster;
    _monster = monster;
}
