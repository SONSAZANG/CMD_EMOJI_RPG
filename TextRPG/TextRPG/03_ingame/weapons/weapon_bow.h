#pragma once
#include "weapon.h"

class Bow : public Weapon
{
public:
	Bow()
	{
		Init();
		price = 50;
	}

	void Init() override
	{
		SetName("활");
		SetHp(5);
		SetAttackDamage(10);
	}

	void Use() override
	{
		// 구현 해야함
		Sound();
	}

	void Sound() override
	{
		UTIL::UPrintEndl("활을 당겨 적중시킵니다.");
	}
};