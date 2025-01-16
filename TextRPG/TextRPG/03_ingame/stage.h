#pragma once
#include <string>
#include "../02_manager/Monsters.h"
#include "../03_ingame/boss_monster.h"
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

public:
    Stage() : _name("default") {}
    Stage(const string& stageName) : _name(stageName){}
    virtual ~Stage() {}
    string GetName() const { return _name; }
};