#include "Monster_Spawn_Manager.h"
#include <cstdlib> 

Monster MonsterSpawnManager::SpawnRandomMonster()
{

    Player& player = PlayerManager::GetInstance()->GetPlayer();

    return Monster::RandomMonsterSpawn(player);
}
