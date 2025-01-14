#include "health_potion.h"

void HealthPotion::Use(Player* player)
{
	if (player->GetMaxHp() >= player->GetHp() + healthRestore)
	{
		player->SetHp(player->GetHp() + healthRestore);
		cout << u8"체력 " << healthRestore << u8"를 회복했습니다. " <<endl;
	}
	else if (player->GetMaxHp() == player->GetHp()) 
	{
		cout << u8"체력이 가득 찼습니다!" << endl;
	}
	else
	{
		cout << u8"체력 " << player->GetMaxHp()-player->GetHp() << u8"를 회복했습니다. " << endl;
		player->SetHp(player->GetMaxHp());

	}
	cout << u8"현재 체력: " << player->GetHp() << endl;

}
