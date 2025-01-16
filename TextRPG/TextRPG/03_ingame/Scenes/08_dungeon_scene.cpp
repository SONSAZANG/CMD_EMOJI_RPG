#include "08_dungeon_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/scene_manager.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/stage_manager.h"
#include "../../02_manager/Battle_Manager.h"
#include "../../03_ingame/Stage.h"
#include <conio.h>

void DungeonScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(2);

	// 현재 던전의 스테이지 설정
	_currentStage = StageManager::GetInstance()->GetStage();

	DrawMainLayout();
	SelectCommand();
}

void DungeonScene::DrawMainLayout()
{
	GUI::DrawInGameBox();
	// 스테이지 타이틀 설정(왼쪽 상단)
	string stageName = _currentStage.GetName();
	GUI::SettingDungeonTitle(stageName);

	// 몬스터, 플레이어 이름 GUI
	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	string monsterName = _currentStage.GetMonster().GetName();
	GUI::DrawBattleNameingBox(playerName, monsterName);
	int playerLevel = PlayerManager::GetInstance()->GetPlayer().GetLevel();
	int playerExp = PlayerManager::GetInstance()->GetPlayer().GetExp();
	GUI::DrawLevelBox(20, 3, 28, 3, playerLevel, playerExp);

	// 몬스터, 플레이어 HP GUI
	GUI::DrawBattleHpBox(_currentStage.GetMonster());
}

void DungeonScene::SelectCommand()
{
	int num;
	Monster monster = _currentStage.GetMonster();
	while (true)
	{
		GUI::ClearUI();

		if (monster.IsDead() || PlayerManager::GetInstance()->GetPlayer().IsDead())
		{
			// 몬스터나 플레이어 죽으면 탈출
			break;
		}

		DrawStartText();
		num = UTIL::IntegerVerify(num, 1, 3);

		switch (num)
		{
			case 1:
				BattleManager::GetInstance()->AttackTarget(true, monster);
				BattleManager::GetInstance()->AttackTarget(false, monster);
				break;
			case 2:
				// 확인 필요
				BattleManager::GetInstance()->SelectionItem(monster);
				break;
			case 3:
				SceneManager::GetInstance()->LoadScene(EST_LOADING);
				break;
			default:
				break;
		}
	}

	if (BattleManager::GetInstance()->GetIsWin())
	{
		BattleManager::GetInstance()->GetVictoryReWard();
		StageManager::GetInstance()->SetClearStageNum(StageManager::GetInstance()->GetCurrentStageType());
	}

	Sleep(1000);
	SceneManager::GetInstance()->LoadScene(EST_LOADING);
}

void DungeonScene::DrawBossAttack()
{
	system("cls");
	GUI::DrawFullBox();

	string bossName = ustring("🐉버그왕 흑염룡🐉");
	GUI::DrawBossBox(bossName);

	GUI::DrawBossAttack({});
	
	string typing;
	cin >> typing;
}

void DungeonScene::DrawStartText()
{
	string questionText1 = ustring("원하는 동작을 입력하세요.");
	string questionText2 = ustring("1. 공격하기 2. 아이템 사용 3. 도망가기");
	string questionText3 = ustring("");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);
}
