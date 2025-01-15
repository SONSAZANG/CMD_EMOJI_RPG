#include "07_select_stage_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/scene_manager.h"

void SelectStageScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(7);
	
	DrawMainLayout();
	SelectCommand();
}

void SelectStageScene::DrawMainLayout()
{
	GUI::DrawInGameBox();
	GUI::SettingTitle("🗺️ 스테이지 선택");

	string stageText1 = ustring("🕷️거미") + "(✅)";
	string stageText2 = ustring("👹트롤") + "(✅)";
	string stageText3 = ustring("🧌오크") + "(✅)";
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
		// 거미 스테이지
		break;
	case 2:
		// 트롤 스테이지
		break;
	case 3:
		// 오크 스테이지
		break;
	case 4:
		// 보스 몬스터 
		break;
	case 5:
		SceneManager::GetInstance()->LoadScene(EST_LOADING);
		break;
	default:
		break;
	}
}
