#pragma once
#include "weapon_base.h"
#include <iostream>

class Sword : public WeaponBase
{
public:
	void Init() override
	{
		atk = 5;
	}

	void Use() override
	{
		std::cout << "";
	}
};