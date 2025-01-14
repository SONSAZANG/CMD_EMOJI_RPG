#include "Bomb.h"


void Bomb::Use(Player* player, Monster monster)
{
	player->SetAttack(player->GetAttack() + attack);
	cout << u8"공격력 " << attack << u8" 증가했습니다. ";
	cout << u8"현재 공격력: " << player->GetAttack() << endl;
}
