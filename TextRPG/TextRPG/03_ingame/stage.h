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
    Monster _monster;

public:
    Stage() : _name("default"), _monster(Monster()) {}
    Stage(const string& stageName, const Monster& monster)
        : _name(stageName), _monster(monster) {}
    Stage(const string& stageName, const BossMonster& monster)
        : _name(stageName), _monster(monster) {
    }
    virtual ~Stage() {}
    string GetName() const { return _name; }

    const Monster& GetMonster() const {
        return _monster;
    }

};