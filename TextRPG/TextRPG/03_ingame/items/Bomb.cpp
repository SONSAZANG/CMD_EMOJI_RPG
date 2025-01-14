#include "Bomb.h"



void Bomb::Use(Player* player, Monster& monster)
{
	if (monster.GetHp() >= attack)
	{
		cout << u8"폭탄으로 " << monster.GetName() << u8"에게 " << attack << u8"데미지를 입혔습니다." << endl;
		monster.SetHp(monster.GetHp() - attack);
	}
	else
	{
		cout << u8"폭탄으로 " << monster.GetName() << u8"에게 " << monster.GetHp() << u8"데미지를 입혔습니다." << endl;
		monster.SetHp(0);
	}
	cout << monster.GetName() << u8" 남은 체력: " << ((monster.GetHp() < 0) ? 0:monster.GetHp()) << endl;
}

