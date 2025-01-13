#include "game_manager.h"
#include "player_manager.h"
#include "Monster_Spawn_Manager.h"
#include "battle_manager.h"
#include "../03_ingame/player/player.h"
#include "windows.h"

void GameManager::Loading()
{
	cout << "게임을 실행합니다." << endl;

	for (int i = 0; i < 10; i++)
	{
		Sleep(500); // 0.5초 Delay
		cout << "-";
	}
	cout << endl;

	Run();
}

void GameManager::Run()
{
	cout << "TEAM17 TEXTRPG 게임이 실행되었습니다." << endl;

	CreatePlayerBase();
	IsPlaying = true;

	int testCount = 0;
	while (IsPlaying)
	{
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
	// 플레이어 생성
	string playername;
	cout << "플레이어 이름을 입력해주세요: ";
	getline(cin, playername);

	while (playername.empty())
	{
		cout << "이름이 비어 있습니다. 다시 입력해주세요: ";
		getline(cin, playername);
	}

	playerManager = PlayerManager::GetInstance();
	// 한가윤) 다른 함수에서 사용하기 위해 PlayerManeger* 지웠습니다. 
	playerManager->CreatePlayer(playername);

	Player& player = playerManager->GetPlayer();
	cout << "플레이어 생성 완료" << endl;
	cout << "이름: " << player.GetName() << "\n체력: " << player.GetHp() << "\n레벨: " << player.GetLevel()
		<< "\n공격력: " << player.GetAttack() << "\n경험치: " << player.GetExp() << endl;

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
	BattleManager* battlemManager = BattleManager::GetInstance();
	// 전투
	SpawnRandomMonster(); // 몬스터 생성 TEST
	cout << "전투 시작" << endl;

	battlemManager->Excute(); // 몬스터 파라미터로 받을 생각

	cout << "전투 종료" << endl;
}

void GameManager::VisitShop()
{
	if (shopManager == nullptr)
	{
		shopManager = ShopManager::GetInstance();

	}
	Player& player = playerManager->GetPlayer();

	player.GetInventory()->SetGold(40); //전투 후 골드 획득 구현되면 삭제

	shopManager->WelcomShop(player.GetInventory());

	cout << "상점 방문 완료" << endl;
}

void GameManager::Exit()
{
	// 보스몬스터 제거 후 종료
	cout << "게임이 종료되었습니다." << endl;
}
