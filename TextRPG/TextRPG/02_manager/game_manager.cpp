#include "game_manager.h"
#include "player_manager.h"
#include "Battle_Manager.h"
#include "../03_ingame/player/player.h"
#include "Monsters.h"
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

	PlayerManager* playerManager = PlayerManager::GetInstance();
	playerManager->CreatePlayer(playername);

	Player& player = playerManager->GetPlayer();
	cout << "플레이어 생성 완료" << endl;
	cout << "이름: " << player.GetName() << "\n체력: " << player.GetHp() << "\n레벨: " << player.GetLevel()
		<< "\n공격력: " << player.GetAttack() << "\n경험치: " << player.GetExp() << endl;

}

void GameManager::SpawnMonster()
{
	// 몬스터 생성
	int monsterType = rand() % 3 + 1;
	Monsters* monster = nullptr;

// TODO: Playerinfo
	switch (monsterType)
	{
	case MT_GOBLIN:
		//monster = new Goblin(playerManager->GetLevel()); 
		break;
	case MT_ORC:
		//monster = new Orc(playerManager->GetLevel());
		break;
	case MT_TROLL:
		//monster = new Troll(playerManager->GetLevel());
		break;
	}
	
	delete monster; // Temp Delete

}


void GameManager::Battle()
{
	BattleManager* battlemManager = BattleManager::GetInstance();
	battlemManager->Excute();
}

void GameManager::VisitShop()
{
	// 전투 후 상점 방문
	// 상황에 따라서 인벤토리 출력 필요
	cout << "상점 방문 완료" << endl;
}

void GameManager::Exit()
{
	// 보스몬스터 제거 후 종료
	cout << "게임이 종료되었습니다." << endl;
}
