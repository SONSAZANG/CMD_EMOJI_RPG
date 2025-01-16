#include "Bomb.h"
#include "../../04_Util/util.h"


void Bomb::Use(Player* player, Monster& monster)
{
	if (monster.GetHp() >= attack)
	{
		cout << ustring("폭탄으로 ") << monster.GetName() << ustring("에게 ") << attack << ustring("데미지를 입혔습니다.") << endl;
		monster.SetHp(monster.GetHp() - attack);
	}
	else
	{
		cout << ustring("폭탄으로 ") << monster.GetName() << ustring("에게 ") << monster.GetHp() << ustring("데미지를 입혔습니다.") << endl;
		monster.SetHp(0);
	}
	cout << monster.GetName() << ustring(" 남은 체력: ") << ((monster.GetHp() < 0) ? 0:monster.GetHp()) << endl;
}

void Bomb::GetDescription()
{
	{
		uprint(description);
	}
}

