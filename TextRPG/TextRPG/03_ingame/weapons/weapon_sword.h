#pragma once
#include "weapon.h"

class Sword : public Weapon
{
public:
	Sword()
	{
		Init();
		price = 30;
	}

	void Init() override
	{
		SetName("양손검");
		SetHp(100);
		SetAttackDamage(30);
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

	string GetSoundString()
	{
		return "양손으로 검을 내려칩니다.";
	}
};