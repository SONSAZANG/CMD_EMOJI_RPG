#include "game_manager.h"
#include "player_manager.h"
#include "../03_ingame/player/player.h"
#include "windows.h"

void GameManager::Loading()
{
	cout << "������ �����մϴ�." << endl;

	for (int i = 0; i < 10; i++)
	{
		Sleep(500); // 0.5�� Delay
		cout << "-";
	}
	cout << endl;

	Run();
}

void GameManager::Run()
{
	cout << "TEAM17 TEXTRPG ������ ����Ǿ����ϴ�." << endl;

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
	// �÷��̾� ����
	cout << "�÷��̾� ���� �Ϸ�" << endl;
	PlayerManager* playerManager = PlayerManager::GetInstance();
	Player player = playerManager->CreatePlayer();
	cout << "������ �÷��̾� ü��: " << player.GetHp() << endl;
}

void GameManager::Battle()
{
	// ���� ���� �� ����
	cout << "���� ���� �Ϸ�" << endl;
	cout << "���� ����" << endl;
	cout << "���� ����" << endl;
}

void GameManager::VisitShop()
{
	// ���� �� ���� �湮
	// ��Ȳ�� ���� �κ��丮 ��� �ʿ�
	cout << "���� �湮 �Ϸ�" << endl;
}

void GameManager::Exit()
{
	// �������� ���� �� ����
	cout << "������ ����Ǿ����ϴ�." << endl;
}
