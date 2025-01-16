#pragma once
#include "weapon.h"

class Bow : public Weapon
{
public:
	Bow()
	{
		Init();
		price = 30;
	}

	void Init() override
	{
		SetName("활");
		SetHp(20);
		SetAttackDamage(100);
	}

	void Use() override
	{
		Sound();
	}

	void Sound() override
	{
		UTIL::UPrintEndl("활을 당겨 적중시킵니다.");
	}

	string GetSoundString()
	{
		return "활을 당겨 적중시킵니다.";
	}

private:
	bool skillFlag;
};