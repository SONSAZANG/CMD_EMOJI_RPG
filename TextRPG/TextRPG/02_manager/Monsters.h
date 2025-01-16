#pragma once

#include "../03_ingame/player/player.h"

enum monsterType
{
    MT_SPIDER = 1,
    MT_ORC = 2,
    MT_TROLL = 3,
    MT_BOSSMONSTER = 4,
};

class Monster
{
public:
    Monster() {}
    Monster(monsterType type, int hp, int attack, int exp);
    Monster(const Monster& other)
        : _type(other._type), _hp(other._hp), _maxHp(other._maxHp),
        _attack(other._attack), _exp(other._exp), _title(other._title) {
    }

    static Monster SelectMonster(const Player& player);

    int GetHp() const 
    { 
        return _hp; 
    }
    int GetAttack() const { return _attack; }
    int GetMaxHp() const;
    int GetExp() const { return _exp; }
    int GetType() const { return _type; }

    string GetName() const;

    void SetAttack(int attack);
    void SetMaxHp(int maxHp);
    void SetHp(int hp);
    void SetType(monsterType type) { _type = type; }

    void DisplayMonster() const;
    void SetStatus(monsterType type);

    bool IsDead() const;
    void SetDamage(const int damage) 
    { 
        if (damage > _hp)
        {
            _hp = 0;
        }
        else
        {
            _hp -= damage;
        }
    }
    bool IsBoss() const;

private:
    void SetTitle(const string& title);
    const char* GetBaseName() const;

    monsterType _type;
    int _hp;
    int _maxHp;
    int _attack;
    int _exp;
    string _title;
};