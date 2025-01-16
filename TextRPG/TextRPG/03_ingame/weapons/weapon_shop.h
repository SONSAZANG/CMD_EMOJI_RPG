#pragma once
#include "weapon_bow.h"
#include "weapon_sword.h"
#include "weapon_default.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../inventory.h"
#include "../../02_manager/player_manager.h"
#include <vector>

class WeaponShop
{
public:
	WeaponShop()
	{
		weapons.push_back(make_unique<Bow>());
		weapons.push_back(make_unique<Sword>());
	}

	~WeaponShop()
	{
	}

	size_t GetSize() const
	{
		return weapons.size();
	}

	void DisplayWeapons() const
	{
		GUI::ClearUI();
		GUI::GoToXY(4, 21);
		uprint("인벤토리 아이템 목록");
		for (int i = 0; i < weapons.size(); ++i)
		{
			const auto& weapon = weapons[i];
			GUI::GoToXY(4, 22 + i);
			std::cout << i + 1 << ". ";
			std::cout << weapon->GetName();
			std::cout << "가격: " << weapon->GetPrice() << " 골드" << std::endl;
		}
	}

	void BuyWeapon(const int& select, Inventory* inventory)
	{
		if (weapons[select - 1]->GetPrice() > inventory->GetGold())
		{
			std::cout << "골드가 부족합니다." << std::endl;
			return;
		}

		std::cout << weapons[select - 1]->GetName() << "을(를) 구매했습니다!" << std::endl;
		inventory->SetGold(inventory->GetGold() - weapons[select - 1]->GetPrice());
		
		inventory->EquipWeapon(std::move(weapons[select - 1]));
		PlayerManager::GetInstance()->GetPlayer().SetEquipStaus();
		weapons.erase(weapons.begin() + select - 1);
	}

private:
	vector<std::unique_ptr<Weapon>> weapons;
};
