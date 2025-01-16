#include "07_select_stage_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/scene_manager.h"
#include "../../02_manager/stage_manager.h"

void SelectStageScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(3);

	DrawMainLayout();
	SelectCommand();
}

void SelectStageScene::DrawMainLayout()
{
	GUI::DrawInGameBox();
	GUI::SettingTitle("🗺️ 스테이지 선택");

	int clearStageNum = StageManager::GetInstance()->GetClearStageNum();
	string stageText1 = ustring("🕷️거미") + (clearStageNum >= 1 ? "(✅)" : "");
	string stageText2 = ustring("👹트롤") + (clearStageNum >= 2 ? "(✅)" : "");
	string stageText3 = ustring("🧌오크") + (clearStageNum >= 3 ? "(✅)" : "");
	string stageText4 = ustring("[ 🐉보스몬스터 ]");
	vector<string> stageTexts = { stageText1, stageText2, stageText3, stageText4 };
	GUI::DrawStageBox(stageTexts);

	string questionText1 = ustring("스테이지 선택 입니다.");
	string questionText2 = ustring("입장하려는 던전을 입력하세요.");
	string questionText3 = ustring("1. 거미 2. 트롤 3. 오크 4. 보스 몬스터 5. 나가기");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);

	GUI::GoToXY(8, 27);
}

void SelectStageScene::SelectCommand()
{
	int num;
	cin >> num;

	switch (num)
	{
	case 1:
		StageManager::GetInstance()->SetCurrentStageType(EStage_SPIDER);
		break;
	case 2:
		StageManager::GetInstance()->SetCurrentStageType(EStage_TROLL);
		break;
	case 3:
		StageManager::GetInstance()->SetCurrentStageType(EStage_ORC);
		break;
	case 4:
		StageManager::GetInstance()->SetCurrentStageType(EStage_BOSS);
		break;
	case 5:
		SceneManager::GetInstance()->SetStageProgress(2);
		break;
	default:
		break;
	}
	SceneManager::GetInstance()->LoadScene(EST_LOADING);
}
