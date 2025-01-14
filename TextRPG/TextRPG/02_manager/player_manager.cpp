#include "player_manager.h"
#include "../03_ingame/player/player.h"
#include "../04_Util/input_verify.h"
#include <iostream>
#include <string>

using namespace std;

void PlayerManager::CreatePlayer()
{
	// 플레이어 생성
	cout << u8"플레이어 이름을 입력해주세요: ";

	string playername = InputVerify::StringVerify();
	//cin.ignore(); // 개행 문자로 넘어가는 현상 방지
	//getline(cin, playername);

	//while (playername.empty())
	//{
	//	cout << u8"\n이름이 비어 있습니다. 다시 입력해주세요: ";
	//	getline(cin, playername);
	//}
	//cout << endl;
	player.SetName(playername);

	cout << u8"플레이어 생성 완료" << endl;
	GetPlayerInfo();
}

void PlayerManager::GetPlayerInfo()
{
	cout << u8"이름: " << player.GetName() << endl;
	cout << u8"체력: " << player.GetHp() << "/" << player.GetMaxHp() << endl;
	cout << u8"레벨 : " << player.GetLevel() << endl;
	cout << u8"공격력: " << player.GetAttack() << endl;
	cout << u8"경험치: " << player.GetExp() << endl;
}

Player& PlayerManager::GetPlayer()
{
	return player;
}
