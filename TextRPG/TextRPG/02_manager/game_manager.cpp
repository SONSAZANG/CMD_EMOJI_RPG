#include "scene_manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "Monster_Spawn_Manager.h"
#include "battle_manager.h"
#include "../03_ingame/player/player.h"
#include "windows.h"

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
	cout << u8"TEAM17 TEXTRPG 게임이 실행되었습니다." << endl;

	CreatePlayerBase();
	IsPlaying = true;

	int testCount = 0;
	while (IsPlaying)
	{
		if (testCount > 6) IsPlaying = false;
		cout << "-----------------------------------" << endl;
		cout << u8"마을입니다. 원하는 행동을 입력하세요." << endl;
		cout << u8"1. 던전\n2. 상점 \n3. 전직소" << endl;
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
			cout << u8"준비중인 기능입니다." << endl;
			break;
		default:
			cout << u8"잘못된 입력입니다." << endl;
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

	cout << u8"전투 시작" << endl;
	randomMonster.DisplayMonster(); // 몬스터 정보 출력 << battle 쪽으로 필요하면 당겨쓰시면 될 듯

	BattleManager::GetInstance()->Excute(randomMonster); // 몬스터 파라미터로 받을 생각


	// ----------------------  보스 몬스터 로직 -----------------------------------

	Player& player = playerManager->GetPlayer(); // TEST 보스몬스터 스텟을 위해 플레이어 정보 필요

	

	if (player.GetLevel() >= 10)
	{
		cout << u8"당신은 충분히 강해졌습니다. 보스 몬스터에게 도전합니다!" << endl;

		Monster bossMonster = Monster(MT_BOSSMONSTER, 0, 0, 0);
		bossMonster.SetStatus(MT_BOSSMONSTER, player);          // 플레이어 레벨에 따라 보스 몬스터 스탯 설정
		bossMonster.DisplayMonster();                           // 보스 몬스터 정보 출력

		BattleManager::GetInstance()->Excute(bossMonster);

		cout << u8"이걸 이기네..." << endl;

		IsPlaying = false;
		return;
	}


	cout << u8"전투 종료" << endl;
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

	cout << u8"상점 방문 완료" << endl;
}

void GameManager::Exit()
{
	cout << u8"게임이 종료되었습니다." << endl;
}


