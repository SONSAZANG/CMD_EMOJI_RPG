#include "06_job_center_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/scene_manager.h"
void JobCenterScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(2);

	DrawMainLayout();
	SelectCommand();
}

void JobCenterScene::DrawMainLayout()
{
	GUI::DrawInGameBox();

	string sceneTitle = ustring("🏛 전직소");
	GUI::SettingTitle(sceneTitle);

	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	GUI::DrawNamingBox(playerName);

	string archer = ustring("1. 🏹 궁수");
	string warrior = ustring("2. ⚔ 전사");
	string assassin = ustring("3. 🗡 도적");
	vector<string> boxNames = { archer, warrior, assassin };
	GUI::DrawSelectBox(boxNames);

	string questionText1 = ustring("전직소입니다.");
	string questionText2 = ustring("원하는 행동을 입력하세요.");
	string questionText3 = ustring("1. 궁수로 전직 2. 전사로 전직 3. 도적으로 전직 4. 나가기");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);

	GUI::GoToXY(8, 27);
}

void JobCenterScene::SelectCommand()
{
	int num;
	PlayerManager* playerManager = PlayerManager::GetInstance();
	Player& player = playerManager->GetPlayer();

	while (true)
	{
		num = UTIL::IntegerVerify(num, 1, 4);

		switch (num)
		{
			case 1:
				player.ChangeJob("궁수");
				break;
			case 2:
				player.ChangeJob("전사");
				break;
			case 3:
				player.ChangeJob("도적");
				break;
			case 4:
				SceneManager::GetInstance()->LoadScene(EST_LOADING);
				break;
			default:
				UTIL::UPrintEndl("잘못된 입력입니다.");
				break;
		}
	}

}
