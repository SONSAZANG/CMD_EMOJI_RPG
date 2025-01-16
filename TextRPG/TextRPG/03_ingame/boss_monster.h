#pragma once
#include "boss_skill.h"
#include "../02_manager/Monsters.h"
#include "../04_Util/util.h"
class BossMonster : public Monster
{
public:
    BossMonster() = default;
    BossMonster(const Player& player);
    void BossAttack();
    bool IsBerserk() { return GetHp() < GetMaxHp() * 0.3; }
    double getElapsed();
    void CheckStatus();
    void BossHardMode();
    BossSkill GetRandomSkill(EBossSkillType skillType);
    int GetBossHp() { return GetHp(); }
private:
    bool isBerserk;
    double attackTimeLimit;
    string inputText;
    BossSkill _skill;
};

