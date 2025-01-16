#include "scene_manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "Monster_Spawn_Manager.h"
#include "battle_manager.h"
#include "stage_manager.h"
#include "../03_ingame/player/player.h"
#include "windows.h"
#include "../04_Util/util.h"
#include "../03_ingame/weapons/weapon_shop.h"

void GameManager::Init()
{
	SetConsoleOutputCP(CP_UTF8);
	SceneManager::GetInstance()->LoadScene(EST_START);
}

void GameManager::Test()
{
	SetConsoleOutputCP(CP_UTF8);
	PlayerManager::GetInstance()->GetPlayer().SetName("test11");
	// 원하는 씬으로 설정
	SceneManager::GetInstance()->LoadScene(EST_SELECT_STAGE);
}

void GameManager::Run()
{
	system("cls");
	UTIL::UPrintEndl("TEAM17 TEXTRPG 게임이 실행되었습니다.");

	CreatePlayerBase();
	IsPlaying = true;
	Player& player = PlayerManager::GetInstance()->GetPlayer();
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
			if (player.GetLevel() >= 5 && !player.IsJobChosen())
			{
				ChangeJobBase();
			}
			else if (player.GetLevel() < 5)
			{
				UTIL::UPrintEndl("전직할 수 없습니다. (레벨 5 이상 필요)");
			}
			else if (player.IsJobChosen())
			{
				UTIL::UPrintEndl("전직할 수 없습니다. (이미 전직 완료)");
			}
			break;
		default:
			UTIL::UPrintEndl("잘못된 입력입니다.");
			break;
		}

		testCount++;
	}

	if (!IsPlaying)
	{
		Clear();
	}
}

void GameManager::CreatePlayerBase()
{
	PlayerManager::GetInstance()->CreatePlayer();

	Player* player = &PlayerManager::GetInstance()->GetPlayer();
	player->GetInventory()->EquipWeapon(make_unique<DefaultWeapon>());
	player->GainExp(400);
}

void GameManager::SpawnRandomMonster()
{
	MonsterSpawnManager* spawnManager = MonsterSpawnManager::GetInstance();
	Monster randomMonster = spawnManager->SpawnRandomMonster();
}

void GameManager::Battle()
{
	system("cls");

	Player& player = PlayerManager::GetInstance()->GetPlayer();
	player.SetLevel(10);

	if (player.GetLevel() < 10)
	{
		Monster randomMonster = MonsterSpawnManager::GetInstance()->SpawnRandomMonster();
		uprintendl("전투 시작");
		randomMonster.DisplayMonster();
		BattleManager::GetInstance()->Excute(randomMonster);
	}
	else
	{
		BossMonster bossMonster(player);
		uprintendl("보스 전투 시작!");
		bossMonster.DisplayBossUI();
		BattleManager::GetInstance()->BossBattle(player, bossMonster);
	}

	if (!BattleManager::GetInstance()->GetIsWin())
	{
		IsPlaying = false;
	}
}

void GameManager::VisitShop()
{
	uprintendl("--------------------------------");
	Player& player = PlayerManager::GetInstance()->GetPlayer();

}

void GameManager::ChangeJobBase()
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();
}

void GameManager::Clear()
{
	BattleManager::GetInstance()->DeleteInstance();
	JobManager::GetInstance()->DeleteInstance();
	MonsterSpawnManager::GetInstance()->DeleteInstance();
	PlayerManager::GetInstance()->DeleteInstance();
	SceneManager::GetInstance()->DeleteInstance();
	ShopManager::GetInstance()->DeleteInstance();
	StageManager::GetInstance()->DeleteInstance();

	Init();
}


