#include "Bomb.h"


void Bomb::Use(Player* player, Monster monster)
{
	player->SetAttack(player->GetAttack() + attack);
	cout << u8"���ݷ� " << attack << u8" �����߽��ϴ�. ";
	cout << u8"���� ���ݷ�: " << player->GetAttack() << endl;
}
