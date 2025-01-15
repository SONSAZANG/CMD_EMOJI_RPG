#include "04_town_scene.h"
#include "../../04_Util/gui.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/game_manager.h"

#include <vector>
#include <iostream>
using namespace std;

void TownScene::Init()
{
	DrawMainLayout();
	SelectCommand();
}

void TownScene::DrawMainLayout()
{	
	GUI::DrawInGameBox();

	string sceneTitle = ustring("🏡 마을");
	GUI::SettingTitle(sceneTitle);

	string player = PlayerManager::GetInstance()->GetPlayer().GetName();
	GUI::DrawNamingBox(vector<string> { player });

	string dungeon = ustring("1. 🏰 던전");
	string shop = ustring("2. 🏪 상점");
	string jobChangeCenter = ustring("3. 🏛 전직소");
	vector<string> boxNames = { dungeon, shop, jobChangeCenter };
	GUI::DrawSelectBox(boxNames);

	string questionText1 = ustring("마을입니다.");
	string questionText2 = ustring("원하는 행동을 입력하세요.");
	string questionText3 = ustring("1. 던전탐험 2. 상점 방문 3. 전직소 방문(5레벨 부터 이용 가능)");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);

	GUI::GoToXY(8, 27);
}

void TownScene::SelectCommand()
{
	int num;
	cin >> num;
	switch (num)
	{
		case 1:
			SceneManager::GetInstance()->LoadScene(EST_SELECT_STAGE);
			break;
		case 2:
			SceneManager::GetInstance()->LoadScene(EST_SHOP);
			break;
		case 3:
		{
			int playerLevel = PlayerManager::GetInstance()->GetPlayer().GetLevel();
			if (playerLevel >= 5)
			{
				SceneManager::GetInstance()->LoadScene(EST_JOB_CENTER);
			}
			else
			{
				// 실패
			}
			SceneManager::GetInstance()->LoadScene(EST_JOB_CENTER);
			break;
		}
		default:
			UTIL::UPrintEndl("잘못된 입력입니다.");
			break;
	}
}
