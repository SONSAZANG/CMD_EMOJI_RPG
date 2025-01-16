#pragma once
#include <string>
#include "../02_manager/Monsters.h"
using namespace std;

enum EStageType
{
	EStage_SPIDER,
	EStage_TROLL,
	EStage_ORC,
	EStage_BOSS,
};

class Stage
{
protected:
	string _name;
	Monster _monster;

public:
	Stage() { _name = "default"; }
	Stage(const string& stageName, Monster& monster)
	{
		_name = stageName;
		_monster = monster;
	}

	virtual ~Stage() {}
	string GetName() const { return _name; }
	const Monster GetMonster() const { return _monster; }
};