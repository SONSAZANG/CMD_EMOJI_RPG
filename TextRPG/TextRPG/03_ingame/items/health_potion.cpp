#include "health_potion.h"
#include "../../04_Util/util.h"
void HealthPotion::Use(Player* player, Monster& monster)
{
	if (player->GetMaxHp() >= player->GetHp() + healthRestore)
	{
		player->SetHp(player->GetHp() + healthRestore);
		cout << ustring("체력 ") << healthRestore << ustring("를 회복했습니다. ") <<endl;
	}
	else if (player->GetMaxHp() == player->GetHp()) 
	{
		cout << ustring("체력이 가득 찼습니다!") << endl;
	}
	else
	{
		cout << ustring("체력 ") << player->GetMaxHp()-player->GetHp() << ustring("를 회복했습니다. ") << endl;
		player->SetHp(player->GetMaxHp());

	}
	cout << ustring("현재 체력: ") << player->GetHp() << "/" << player->GetMaxHp() << endl;
}
