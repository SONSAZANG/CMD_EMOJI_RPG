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
	Monster randomMonster = MonsterSpawnManager::GetInstance()->SpawnRandomMonster();
	UTIL::UPrintEndl("전투 시작");
	randomMonster.DisplayMonster(); // 몬스터 정보 출력 << battle 쪽으로 필요하면 당겨쓰시면 될 듯

	BattleManager::GetInstance()->Excute(randomMonster); // 몬스터 파라미터로 받을 생각


	// ----------------------  보스 몬스터 로직 -----------------------------------

	Player& player = playerManager->GetPlayer(); // TEST 보스몬스터 스텟을 위해 플레이어 정보 필요

	

	if (player.GetLevel() >= 10)
	{
		UTIL::UPrintEndl("당신은 충분히 강해졌습니다. 보스 몬스터에게 도전합니다!");

		Monster bossMonster = Monster(MT_BOSSMONSTER, 0, 0, 0);
		bossMonster.SetStatus(MT_BOSSMONSTER, player);          // 플레이어 레벨에 따라 보스 몬스터 스탯 설정
		bossMonster.DisplayMonster();                           // 보스 몬스터 정보 출력

		BattleManager::GetInstance()->Excute(bossMonster);

		UTIL::UPrintEndl("이걸 이기네...");

		IsPlaying = false;
		return;
	}

	UTIL::UPrintEndl("전투 종료");
}

void GameManager::VisitShop()
{
	cout << "---------------------------------------------------------------" << endl;
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


