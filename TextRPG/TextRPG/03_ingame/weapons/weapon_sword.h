#pragma once
#include "weapon.h"

class Sword : public Weapon
{
public:
	Sword()
	{
		Init();
	}

	void Init() override
	{
		SetName("양손검");
		SetHp(10);
		SetAttackDamage(5);
	}

	void Use() override
	{
		// 구현 해야함
		Sound();
	}

	void Sound() override
	{
		UTIL::UPrintEndl("양손으로 검을 내려칩니다.");
	}
};