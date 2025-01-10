#include "game_manager.h"
#include "player_manager.h"
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

	CreatePlayer();

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

void GameManager::CreatePlayer()
{
	// 플레이어 생성
	cout << "플레이어 생성 완료" << endl;
	PlayerManager* playerManager = PlayerManager::GetInstance();
	Player player = playerManager->CreatePlayer();
	cout << "생성된 플레이어 체력: " << player.GetHp() << " 레벨: " << playerManager->GetLevel() << endl;
	cout << "캬 버그좀 느껴봐라~~" << endl;
}

void GameManager::Battle()
{
	// 몬스터 생성 후 전투
	cout << "몬스터 생성 완료" << endl;
	cout << "전투 시작" << endl;
	cout << "전투 종료" << endl;
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
