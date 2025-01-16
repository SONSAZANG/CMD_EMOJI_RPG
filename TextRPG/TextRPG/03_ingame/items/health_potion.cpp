#include "health_potion.h"
#include "../../04_Util/util.h"
#include "../../04_Util/gui.h"
void HealthPotion::Use(Player* player, Monster& monster)
{
	if (player->GetMaxHp() >= player->GetHp() + healthRestore)
	{
		player->SetHp(player->GetHp() + healthRestore);
		GUI::GoToXY(4, 22);
		cout << ustring("체력 ") << healthRestore << ustring("를 회복했습니다. ");
	}
	else if (player->GetMaxHp() == player->GetHp()) 
	{
		GUI::GoToXY(4, 22);
		cout << ustring("체력이 가득 찼습니다!");
	}
	else
	{
		GUI::GoToXY(4, 22);
		cout << ustring("체력 ") << player->GetMaxHp()-player->GetHp() << ustring("를 회복했습니다. ");
		player->SetHp(player->GetMaxHp());

	}
	GUI::GoToXY(4, 23);
	cout << ustring("현재 체력: ") << player->GetHp() << "/" << player->GetMaxHp();
}

void HealthPotion::GetDescription()
{
	{
		uprint(description);
	}
}
