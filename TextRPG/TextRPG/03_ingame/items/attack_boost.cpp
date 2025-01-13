#include "attack_boost.h"

void AttackBoost::Use(Player* player)
{
	player->SetAttack(player->GetAttack() + attackIncrease);
	cout << "Attack " << attackIncrease << "가 증가했습니다. ";
	cout << "현재 Attack: " << player->GetAttack() << endl;
}
