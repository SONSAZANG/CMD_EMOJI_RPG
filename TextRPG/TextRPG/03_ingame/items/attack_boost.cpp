#include "attack_boost.h"

void AttackBoost::Use(Player* player, Monster& monster)
{
	player->SetAttack(player->GetAttack() + attackIncrease);
	cout << u8"공격력 " << attackIncrease << u8" 증가했습니다. ";
	cout << u8"현재 공격력: " << player->GetAttack() << endl;
}
