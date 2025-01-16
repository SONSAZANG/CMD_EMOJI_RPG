#include "attack_boost.h"
#include "../../04_Util/util.h"
#include "../../04_Util/gui.h"
void AttackBoost::Use(Player* player, Monster& monster)
{
	player->SetAttack(player->GetAttack() + attackIncrease);
	GUI::GoToXY(4, 21);
	cout << ustring("공격력 ") << attackIncrease << ustring(" 증가했습니다. ");
	GUI::GoToXY(4, 22);
	cout << ustring(ustring("현재 공격력: ")) << player->GetAttack();
}

void AttackBoost::GetDescription()
{
	{
		uprint(description);
	}
}
