#include "08_dungeon_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/scene_manager.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/stage_manager.h"
void DungeonScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(8);


	DrawMainLayout();
	SelectCommand();
}

void DungeonScene::DrawMainLayout()
{
	GUI::DrawInGameBox();
	Stage stage = StageManager::GetInstance()->GetStage();
	string stageName = StageManager::GetInstance()->GetCurrentStageName();
	GUI::SettingDungeonTitle(stageName);

	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	string monsterName = stage.GetMonster().GetName();
	GUI::DrawNamingBox({ playerName, monsterName });

	string questionText1 = ustring("원하는 동작을 입력하세요.");
	string questionText2 = ustring("1. 공격하기 2. 아이템 사용 3. 도망가기");
	string questionText3 = ustring("");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);

	GUI::GoToXY(8, 27);
}

void DungeonScene::SelectCommand()
{
	while(cin);
}
