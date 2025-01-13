#include "health_potion.h"

void HealthPotion::Use(Player* player)
{
	player->SetHp(player->GetHp() + healthRestore);
	cout << "Hp " << healthRestore << "를 회복했습니다. ";
	cout << "현재 Hp: " << player->GetHp() << endl;
}
