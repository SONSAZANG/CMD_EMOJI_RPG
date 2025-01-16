#include "Bomb.h"
#include "../../04_Util/util.h"
#include "../../04_Util/gui.h"
void Bomb::Use(Player* player, Monster& monster)
{
	if (monster.GetHp() >= attack)
	{
		GUI::GoToXY(4, 22);
		cout << ustring("폭탄으로 ") << monster.GetName() << ustring("에게 ") << attack << ustring("데미지를 입혔습니다.");
		monster.SetHp(monster.GetHp() - attack);
		GUI::DrawBattleHpBox(monster);
	}
	else
	{
		GUI::GoToXY(4, 22);
		cout << ustring("폭탄으로 ") << monster.GetName() << ustring("에게 ") << monster.GetHp() << ustring("데미지를 입혔습니다.");
		monster.SetHp(0);
	}
	GUI::GoToXY(4, 23);
	cout << monster.GetName() << ustring(" 남은 체력: ") << ((monster.GetHp() < 0) ? 0:monster.GetHp());
}

void Bomb::GetDescription()
{
	{
		uprint(description);
	}
}

