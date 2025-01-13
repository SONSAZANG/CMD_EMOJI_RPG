#include "player_manager.h"
#include "../03_ingame/player/player.h"
#include <iostream>
#include <string>

using namespace std;

void PlayerManager::CreatePlayer()
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

	player.SetName(playername);
}

Player& PlayerManager::GetPlayer()
{
	return player;
}
