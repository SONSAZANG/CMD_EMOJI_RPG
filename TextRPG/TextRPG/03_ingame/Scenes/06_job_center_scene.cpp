#include "06_job_center_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/scene_manager.h"
void JobCenterScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(6);

	DrawMainLayout();
	SelectCommand();
}

void JobCenterScene::DrawMainLayout()
{
	GUI::DrawInGameBox();

	string sceneTitle = ustring("🏛 전직소");
	GUI::SettingTitle(sceneTitle);

	string player = PlayerManager::GetInstance()->GetPlayer().GetName();
	GUI::DrawNamingBox(vector<string> { player });

	string archer = ustring("1. 🏹 궁수");
	string warrior = ustring("2. ⚔ 전사");
	string assassin = ustring("3. 🗡 도적");
	vector<string> boxNames = { archer, warrior, assassin };
	GUI::DrawSelectBox(boxNames);

	string questionText1 = ustring("전직소입니다.");
	string questionText2 = ustring("원하는 행동을 입력하세요.");
	string questionText3 = ustring("1. 궁수로 전직 2. 전사로 전직 3. 도적으로 전직 3. 나가기");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);

	GUI::GoToXY(8, 27);
}

void JobCenterScene::SelectCommand()
{
	// TODO: 민수님 여기 전직 기능 연결 부탁드립니다.( 은수 ) 
	int num;
	cin >> num;
	switch (num)
	{
		case 1:
			// 궁수 전직
			break;
		case 2:
			// 전사 전직
			break;
		case 3:
			SceneManager::GetInstance()->LoadScene(EST_LOADING);
			break;
		default:
			break;
	}
}
