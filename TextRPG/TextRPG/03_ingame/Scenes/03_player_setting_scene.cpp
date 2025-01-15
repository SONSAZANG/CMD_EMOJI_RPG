#include "03_player_setting_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/game_manager.h"
#include <conio.h>
void PlayerSettingScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(3);

	DrawMainLayout();
	SettingPlayerName();
	DrawMainLayout2();
	SelectCommand();
}

void PlayerSettingScene::DrawMainLayout()
{
	GUI::DrawInGameBox();

	string sText1 = ustring("으윽..여긴 어디지..? 잠들었었나?");
	string sText2 = ustring("나 텍스트 RPG 만들고 있었는데...");
	string sText3 = ustring("뭐야 왜 이렇게 다 까매... 저건..글자?");
	vector<string> storyTexts = { sText1, sText2, sText3 };
	GUI::DrawStoryBox(storyTexts);

	string questionText1 = ustring("당신은 용사입니다.");
	string questionText2 = ustring("플레이어 이름을 입력하세요.");
	string questionText3 = ustring("");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);
}

void PlayerSettingScene::SettingPlayerName()
{	
	GUI::GoToXY(8, 27);
	uprint(" ");
	GameManager::GetInstance()->CreatePlayerBase();
}

void PlayerSettingScene::DrawMainLayout2()
{
	system("cls");

	GUI::DrawInGameBox();
	GUI::DrawStartStory();

	string questionText1 = ustring("마을을 발견했습니다.");
	string questionText2 = ustring("원하는 행동을 입력하세요.");
	string questionText3 = ustring("1. 마을로 이동한다.");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);
}

void PlayerSettingScene::SelectCommand()
{
	_getch();
	SceneManager::GetInstance()->LoadScene(EST_LOADING);
}