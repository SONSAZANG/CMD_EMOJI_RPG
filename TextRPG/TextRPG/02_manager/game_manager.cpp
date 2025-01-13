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
		system("cls");
		if (testCount > 3) IsPlaying = false;
		Battle();
		VisitShop();
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

	Player& player = playerManager->GetPlayer();

	// TEST 몬스터 스텟 및 플레이어 레벨 출력
	cout << "Player Level: " << player.GetLevel() << endl;
	cout << "Monster Type: " << randomMonster.GetName() << endl;
	cout << "Monster Hp: " << randomMonster.GetHp() << endl;
	cout << "Monster Attack: " << randomMonster.GetAttack() << endl;
	cout << "Monster Exp: " << randomMonster.GetExp() << endl;

}

void GameManager::Battle()
{
	Monster randomMonster = MonsterSpawnManager::GetInstance()->SpawnRandomMonster();

	cout << u8"전투 시작" << endl;

	BattleManager::GetInstance()->Excute(randomMonster); // 몬스터 파라미터로 받을 생각


	//아이템 사용 테스트 코드 시작
	Player& player = playerManager->GetPlayer();
	player.UseItem();
	//아이템 사용 테스트 코드 끝

	cout << u8"전투 종료" << endl;
}

void GameManager::VisitShop()
{
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
	// 보스몬스터 제거 후 종료
	cout << u8"게임이 종료되었습니다." << endl;
}


