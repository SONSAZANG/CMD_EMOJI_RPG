#pragma once

#include "../03_ingame/player/player.h"

enum monsterType
{
    MT_GOBLIN = 1,
    MT_ORC = 2,
    MT_TROLL = 3,
    MT_BOSSMONSTER = 4,
};

class Monster
{
public:
    Monster(monsterType type, int hp, int attack, int exp);

    static Monster RandomMonsterSpawn(const Player& player);

    int GetHp() const { return _hp; }
    int GetAttack() const { return _attack; }
    int GetExp() const { return _exp; }
    int GetType() const { return _type; }

    string GetName() const;

    void SetAttack(int attack);
    void SetHp(int hp);

private:
    void SetStatus(monsterType type, const Player& player);
    void SetTitle(const string& title);
    const char* GetBaseName() const;

    monsterType _type;
    int _hp;
    int _attack;
    int _exp;
    string _title;
};
