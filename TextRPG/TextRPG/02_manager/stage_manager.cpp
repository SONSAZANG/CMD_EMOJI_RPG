#include "stage_manager.h"
#include "../03_ingame/stage.h"
#include "Monsters.h"
Stage& StageManager::GetStage()
{	
	if (!currentStage)
	{
		*currentStage = CreateStage(stageType);
	}
	return *currentStage;
}
Stage StageManager::CreateStage(EStageType stageType)
{
	Stage stage;
	Monster selectedMonster(MT_SPIDER, 0, 0, 0);

	switch (stageType)
	{
	case EStage_SPIDER:
		selectedMonster.SetStatus(MT_SPIDER);
		stage = Stage(ustring("SPIDER"), selectedMonster);
		break;
	case EStage_TROLL:
		selectedMonster.SetStatus(MT_TROLL);
		stage = Stage(ustring("TROLL"), selectedMonster);
		break;
	case EStage_ORC:
		selectedMonster.SetStatus(MT_ORC);
		stage = Stage(ustring("ORC"), selectedMonster);
		break;
	case EStage_BOSS:
		selectedMonster.SetStatus(MT_BOSSMONSTER);
		stage = Stage(ustring("BOSS"), selectedMonster);
		break;
	default:
		break;
	}

	return stage;
}