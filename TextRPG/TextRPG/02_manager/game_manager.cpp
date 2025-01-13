#include "game_manager.h"
#include "player_manager.h"
#include "battle_manager.h"
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
	// 전투
	cout << "몬스터 생성 완료" << endl;
	cout << "전투 시작" << endl;

	battlemManager->Excute(); // 몬스터 파라미터로 받을 생각


	//아이템 사용 테스트 코드 시작
	Player& player = playerManager->GetPlayer();

	player.SetHp(100);
	player.UseItem();
	//아이템 사용 테스트 코드 끝

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
