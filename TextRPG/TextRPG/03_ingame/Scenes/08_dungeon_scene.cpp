#include "08_dungeon_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/scene_manager.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/stage_manager.h"
#include "../../02_manager/Battle_Manager.h"
#include "../../02_manager/monster_Manager.h"
#include "../../03_ingame/Stage.h"
#include "../../03_ingame/boss_monster.h"
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
	Monster& monster = MonsterManager::GetInstance()->GetMonster();
	
	GUI::DrawInGameBox();
	// 스테이지 타이틀 설정(왼쪽 상단)
	string stageName = _currentStage.GetName();
	GUI::SettingDungeonTitle(stageName);

	// 몬스터, 플레이어 이름 GUI
	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	string monsterName = monster.GetName();
	GUI::DrawBattleNameingBox(playerName, monsterName);
	int playerLevel = PlayerManager::GetInstance()->GetPlayer().GetLevel();
	int playerExp = PlayerManager::GetInstance()->GetPlayer().GetExp();
	GUI::DrawLevelBox(20, 3, 28, 3, playerLevel, playerExp);

	// 몬스터, 플레이어 HP GUI
	GUI::DrawBattleHpBox();
}

void DungeonScene::SelectCommand()
{
	int num;
	Monster& monster = MonsterManager::GetInstance()->GetMonster();
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
				if (!monster.IsBoss()) 
				{
					BattleManager::GetInstance()->AttackTarget(true);
					if (monster.IsDead()) break;
					BattleManager::GetInstance()->AttackTarget(false);
				}
				else
				{
					DrawBossAttack();
				}
				break;
			case 2:
				// 확인 필요
				BattleManager::GetInstance()->SelectionItem();
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
	else
	{	
		// 보스전에서 지면 끝남
		if (monster.IsBoss())
		{
			SceneManager::GetInstance()->LoadScene(EST_END);
		}
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
	
	BossMonster& bossMonster = MonsterManager::GetInstance()->GetBossMonster();
	
	bossMonster.BossAttack();

	if (bossMonster.IsDead())
	{
		StageManager::GetInstance()->SetClearStageNum(4);
		SceneManager::GetInstance()->LoadScene(EST_END);
	}

	DrawMainLayout();
	GUI::DrawBattleHpBox();
}

void DungeonScene::DrawStartText()
{
	string questionText1 = ustring("원하는 동작을 입력하세요.");
	string questionText2 = ustring("1. 공격하기 2. 아이템 사용 3. 도망가기");
	string questionText3 = ustring("");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);
}
