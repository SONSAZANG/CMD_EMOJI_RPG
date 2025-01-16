#include "stage_manager.h"
#include "../03_ingame/stage.h"

using namespace std;

Stage& StageManager::GetStage()
{
    if (!currentStage) 
    {
        currentStage = CreateStage(stageType); 
        if (!currentStage) throw runtime_error("Failed to Create Stage");
    }
    cout << "Current Stage: " << currentStage->GetName() << endl;
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
        break;
    case EStage_TROLL:
        selectedMonster.SetStatus(MT_ORC);
        break;
    case EStage_ORC:
        selectedMonster.SetStatus(MT_TROLL);
        break;
    case EStage_BOSS:
        selectedMonster.SetStatus(MT_BOSSMONSTER);
        break;
    default:
        break;
    }

    return stage;
}