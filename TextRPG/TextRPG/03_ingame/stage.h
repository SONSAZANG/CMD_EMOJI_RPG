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
	string name;
	Monster monster;
	bool isClear;

public:
	Stage() {}
	Stage(const string& stageName, Monster& monster)
	{
		name = stageName;
		monster = monster;
		isClear = false;
	}

	virtual ~Stage() {}

	void SetClear(bool clear) { isClear = clear; }
	bool IsClear() const { return isClear; }
	string GetName() const { return name; }
	const Monster GetMonster() const { return monster; }
};