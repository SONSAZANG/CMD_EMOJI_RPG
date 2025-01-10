#pragma once


class MonsterSpawnManager
{
public:
	MonsterSpawnManager(int monsterType)
		: _monsterType(monsterType), _hp(0), _attack(0), _exp(0)
	{
	}

	virtual ~MonsterSpawnManager() {}

	int GetHp() const { return _hp; }
	int GetAttack() const { return _attack; }

	//void Battle(); << TODO : Call Battle

protected:
	int _monsterType;
	int _hp;
	int _attack;
	int _exp;
};

