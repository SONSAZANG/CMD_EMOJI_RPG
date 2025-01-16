#pragma once
#include <string>

enum EBossSkillType {
    FIRE = 0,
    ICE,
    THUNDER,
    SHADOW,
    EARTHQUAKE,
    POISON,
    WIND,
    HOLY,
    DARK,
};

class BossSkill {
public:
    EBossSkillType skillType;
    std::string nameText;
    std::string evadeText;
    std::string skillText;

    BossSkill() : skillType(FIRE), nameText(""), evadeText(""), skillText("") {}
    BossSkill(EBossSkillType type, std::string name, std::string evade, std::string skill)
        : skillType(type), nameText(name), evadeText(evade), skillText(skill) {
    }
};