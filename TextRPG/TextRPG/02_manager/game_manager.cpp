#include "scene_manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "monster_manager.h"
#include "battle_manager.h"
#include "stage_manager.h"
#include "../03_ingame/player/player.h"
#include "windows.h"
#include "../04_Util/util.h"
#include "../03_ingame/weapons/weapon_shop.h"
#include "../03_ingame/boss_monster.h"

void GameManager::Init()
{
	SetConsoleOutputCP(CP_UTF8);
	SceneManager::GetInstance()->LoadScene(EST_START);
}

void GameManager::Test()
{
	SetConsoleOutputCP(CP_UTF8);
	PlayerManager::GetInstance()->GetPlayer().SetName("손사장");
	PlayerManager::GetInstance()->GetPlayer().SetMaxHp(500);
	PlayerManager::GetInstance()->GetPlayer().SetHp(500);
	PlayerManager::GetInstance()->GetPlayer().SetAttack(600);
	// 원하는 씬으로 설정
	PlayerManager::GetInstance()->GetPlayer().SetLevel(10);
	StageManager::GetInstance()->SetClearStageNum(3);
	SceneManager::GetInstance()->LoadScene(EST_SELECT_STAGE);
}

void GameManager::CreatePlayerBase()
{
	PlayerManager::GetInstance()->CreatePlayer();
	Player* player = &PlayerManager::GetInstance()->GetPlayer();
	player->GetInventory()->EquipWeapon(make_unique<DefaultWeapon>());
}

void GameManager::Clear()
{
	BattleManager::GetInstance()->DeleteInstance();
	JobManager::GetInstance()->DeleteInstance();
	MonsterManager::GetInstance()->DeleteInstance();
	PlayerManager::GetInstance()->DeleteInstance();
	SceneManager::GetInstance()->DeleteInstance();
	ShopManager::GetInstance()->DeleteInstance();
	StageManager::GetInstance()->DeleteInstance();
	MonsterManager::GetInstance()->DeleteInstance();

	Init();
}


