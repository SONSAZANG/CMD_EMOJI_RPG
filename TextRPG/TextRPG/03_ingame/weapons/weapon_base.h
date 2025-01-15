#pragma once

class WeaponBase
{
public:
	virtual void Init() = 0;
	virtual void Use() = 0;

protected:
	int atk;
};