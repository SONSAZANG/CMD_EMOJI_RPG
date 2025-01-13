#include "attack_boost.h"

void AttackBoost::Use(Player* player)
{
	player->SetAttack(player->GetAttack() + attackIncrease);
	cout << "공격력 " << attackIncrease << " 증가했습니다. ";
	cout << "현재 공격력: " << player->GetAttack() << endl;
}
