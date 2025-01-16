#pragma once
#include "boss_skill.h"
#include "../02_manager/Monsters.h"
#include "../04_Util/util.h"
class BossMonster : public Monster
{
public:
    BossMonster(const Player& player);
    void BossAttack();
    bool IsBerserk() { return GetHp() < bossMaxHp * 0.9; }
    double getElapsed();
    void CheckStatus();
    void BossHardMode();
    BossSkill GetRandomSkill(EBossSkillType skillType);
private:
    bool isBerserk;
    const int bossMaxHp = GetHp();
    double attackTimeLimit = 2.0;
    string inputText;
    BossSkill _skill;
};

