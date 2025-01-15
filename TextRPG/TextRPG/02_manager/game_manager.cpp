#include "scene_manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "Monster_Spawn_Manager.h"
#include "battle_manager.h"
#include "../03_ingame/player/player.h"
#include "windows.h"
#include "../04_Util/util.h"

void GameManager::Init()
{
	if (sceneManager == nullptr)
	{
		sceneManager = SceneManager::GetInstance();
	}
	SetConsoleOutputCP(CP_UTF8);

	sceneManager->LoadScene(EST_START);
}

void GameManager::Run()
{
	system("cls");
	UTIL::UPrintEndl("TEAM17 TEXTRPG 게임이 실행되었습니다.");

	CreatePlayerBase();
	IsPlaying = true;

	int testCount = 0;
	while (IsPlaying)
	{
		if (testCount > 6) IsPlaying = false;
		UTIL::UPrintEndl("-----------------------------------");
		UTIL::UPrintEndl("마을입니다.원하는 행동을 입력하세요.");
		UTIL::UPrintEndl("1. 던전\n2.상점 \n3.전직소");
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			Battle();
			break;
		case 2:
			VisitShop();
			break;
		case 3:
			UTIL::UPrintEndl("준비중인 기능입니다.");
			break;
		default:
			UTIL::UPrintEndl("잘못된 입력입니다.");
			break;
		}

		testCount++;
	}

	if (!IsPlaying)
	{
		Exit();
	}
}

void GameManager::CreatePlayerBase()
{
	playerManager = PlayerManager::GetInstance();
	playerManager->CreatePlayer();

	Player& player = playerManager->GetPlayer();
}

void GameManager::SpawnRandomMonster()
{
	MonsterSpawnManager* spawnManager = MonsterSpawnManager::GetInstance();
	Monster randomMonster = spawnManager->SpawnRandomMonster();
}

void GameManager::Battle()
{
	system("cls");

	//playerManager->GetPlayer().SetLevel(10); // test

	Monster monster = playerManager->GetPlayer().GetLevel() < 10 ?
		MonsterSpawnManager::GetInstance()->SpawnRandomMonster() : BossMonster(playerManager->GetPlayer()); // 플레이어 레벨에 따른 몬스터 호출

	uprintendl("전투 시작");
	monster.DisplayMonster();
	

	BattleManager::GetInstance()->Excute(monster);

	if (!BattleManager::GetInstance()->GetIsWin())
		IsPlaying = false;
}

void GameManager::VisitShop()
{
	uprintendl("--------------------------------");
	if (shopManager == nullptr)
	{
		shopManager = ShopManager::GetInstance();

	}
	Player& player = playerManager->GetPlayer();

	shopManager->WelcomShop(player.GetInventory());
	UTIL::UPrintEndl("상점 방문 완료");
}

void GameManager::Exit()
{
	UTIL::UPrintEndl("게임이 종료되었습니다.");
}


