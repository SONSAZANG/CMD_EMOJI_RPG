#include "08_dungeon_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/scene_manager.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/stage_manager.h"
#include "../../02_manager/Battle_Manager.h"
#include "../../03_ingame/Stage.h"


void DungeonScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(2);

	auto& stage = StageManager::GetInstance()->GetStage();
	Monster monster = stage.GetMonster();

	DrawMainLayout();
	SelectCommand(monster); // monster를 전달
}

void DungeonScene::DrawMainLayout()
{
	GUI::DrawInGameBox();
	Stage* stage = new Stage(StageManager::GetInstance()->GetStage());
	string stageName = StageManager::GetInstance()->GetCurrentStageName();
	GUI::SettingDungeonTitle(stageName);

	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	string monsterName = stage->GetMonster().GetName();
	GUI::DrawBattleNameingBox(playerName, monsterName);

	// 턴 지날때마다 호출 필요 -> HP 그려줌
	GUI::DrawBattleHpBox();

	delete stage;
}

void DungeonScene::SelectCommand(Monster& monster) // 매개변수 추가
{
	BattleManager battleManager;
	battleManager.SelectionBehavior(monster);

	if (battleManager.GetIsWin())
	{
		StageManager::GetInstance()->SetClearStageNum
		(StageManager::GetInstance()->GetCurrentStageType());
	}

	Sleep(3000);
	SceneManager::GetInstance()->LoadScene(EST_TOWN);
}