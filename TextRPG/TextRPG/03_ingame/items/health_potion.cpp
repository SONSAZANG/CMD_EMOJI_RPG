#include "health_potion.h"

void HealthPotion::Use(Player* player)
{
	if (player->GetMaxHp() >= player->GetHp() + healthRestore)
	{
		player->SetHp(player->GetHp() + healthRestore);
		cout << "체력 " << healthRestore << "를 회복했습니다. " <<endl;
	}
	else if (player->GetMaxHp() == player->GetHp()) 
	{
		cout << "체력이 가득 찼습니다!" << endl;
	}
	else
	{
		cout << "체력 " << player->GetMaxHp()-player->GetHp() << "를 회복했습니다. " << endl;
		player->SetHp(player->GetMaxHp());

	}
	cout << "현재 체력: " << player->GetHp() << endl;

}
