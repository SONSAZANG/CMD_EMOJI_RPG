#include "stage_manager.h"
#include "player_manager.h"
#include "monster_manager.h"
#include "../03_ingame/stage.h"

using namespace std;

Stage& StageManager::GetStage()
{
	currentStage = CreateStage(stageType);
    return *currentStage;
}

unique_ptr<Stage> StageManager::CreateStage(EStageType stageType)
{
    auto stage = make_unique<Stage>();
    Monster selectedMonster(MT_SPIDER, 0, 0, 0);
	
	switch (stageType)
	{
	case EStage_SPIDER:
		selectedMonster.SetStatus(MT_SPIDER);
		MonsterManager::GetInstance()->SetMonster(selectedMonster);
		*stage = Stage(ustring("SPIDER"));
		break;
	case EStage_TROLL:
		selectedMonster.SetStatus(MT_TROLL);
		MonsterManager::GetInstance()->SetMonster(selectedMonster);
		*stage = Stage(ustring("TROLL"));
		break;
	case EStage_ORC:
		selectedMonster.SetStatus(MT_ORC);
		MonsterManager::GetInstance()->SetMonster(selectedMonster);
		*stage = Stage(ustring("ORC"));
		break;
	case EStage_BOSS:
		BossMonster bossMonster(PlayerManager::GetInstance()->GetPlayer());
		MonsterManager::GetInstance()->SetMonster(bossMonster);
		*stage = Stage(ustring("BOSS"));
		break;
	}

    return stage;
}