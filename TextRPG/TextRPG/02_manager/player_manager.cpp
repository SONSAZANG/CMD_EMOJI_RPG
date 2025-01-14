#include "player_manager.h"
#include "../03_ingame/player/player.h"
#include "../04_Util/util.h"
#include <iostream>
#include <string>

using namespace std;

void PlayerManager::CreatePlayer()
{
	// 플레이어 생성
	UTIL::UPrint("플레이어 이름을 입력해주세요: ");
	string playername = UTIL::StringVerify();
	player.SetName(playername);
	UTIL::UPrintEndl("플레이어 생성 완료");
	GetPlayerInfo();
}

void PlayerManager::GetPlayerInfo()
{
	cout << UTIL::UString("이름: ") << player.GetName() << endl;
	cout << UTIL::UString("체력: ") << player.GetHp() << endl;
	cout << UTIL::UString("레벨: ") << player.GetLevel() << endl;
	cout << UTIL::UString("공격력: ") << player.GetAttack() << endl;
	cout << UTIL::UString("경험치: ") << player.GetExp() << endl;
	cout << UTIL::UString("최대체력: ") << player.GetMaxHp() << endl;
}

Player& PlayerManager::GetPlayer()
{
	return player;
}
