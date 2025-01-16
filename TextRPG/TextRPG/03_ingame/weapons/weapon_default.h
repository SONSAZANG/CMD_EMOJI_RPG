#pragma once
#include "weapon.h"

class DefaultWeapon : public Weapon
{
public:
	DefaultWeapon()
	{
		Init();
	}

	void Init() override
	{
		SetName("짱돌");
		SetHp(0);
		SetAttackDamage(0);
	}

	void Use() override
	{
		Sound();
	}

	void Sound() override
	{
		UTIL::UPrintEndl("짱돌을 던집니다.");
	}
};