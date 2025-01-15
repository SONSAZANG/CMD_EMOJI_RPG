#pragma once
#include "../../04_Util/util.h"

class Weapon
{
public:
	Weapon() : m_name(""), m_atk(0), m_hp(0)
	{
	}

	virtual void Init() = 0;
	virtual void Use() = 0;
	virtual void Sound() = 0;

	std::string& GetName()
	{
		return m_name;
	}
	int GetHp()
	{
		return m_hp;
	}
	int GetAttack()
	{
		return m_atk;
	}

	void SetName(const std::string& name)
	{
		m_name = name;
	}
	void SetHp(const int& hp)
	{
		m_hp = hp;
	}
	void SetAttackDamage(const int& atk)
	{
		m_atk = atk;
	}

	virtual void PrintStatus()
	{
		cout << UTIL::UString("이름: ") << GetName() << endl;
		cout << UTIL::UString("증가 체력: ") << GetHp() << endl;
		cout << UTIL::UString("공격력: ") << GetAttack() << endl;
	}

private:
	std::string m_name;
	int m_hp;
	int m_atk;
};