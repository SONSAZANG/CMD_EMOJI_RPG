#include "attack_boost.h"
#include "../../04_Util/util.h"
void AttackBoost::Use(Player* player, Monster& monster)
{
	player->SetAttack(player->GetAttack() + attackIncrease);
	cout << ustring("공격력 ") << attackIncrease << ustring(" 증가했습니다. ");
	cout << ustring(u8"현재 공격력: ") << player->GetAttack() << endl;
}
