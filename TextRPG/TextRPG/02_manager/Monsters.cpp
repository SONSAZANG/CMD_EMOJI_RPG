#include "Monsters.h"
#include <cstdlib>
#include <ctime>

Monster::Monster(monsterType type, int hp, int attack, int exp)
    : _type(type), _hp(hp), _attack(attack), _exp(exp) {
}

Monster Monster::RandomMonsterSpawn(const Player& player)
 {

    srand(static_cast<unsigned int>(time(nullptr)));

    monsterType randomType = static_cast<monsterType>(1 + rand() % 3);

    Monster monster(randomType, 0, 0, 0);
    monster.SetStatus(randomType, player);
    return monster;
}

const char* Monster::GetName() const
{
    switch (_type) {
    case MT_GOBLIN:
        return "Goblin";
    case MT_ORC:
        return "Orc";
    case MT_TROLL:
        return "Troll";
    case MT_BOSSMONSTER:
        return "Boss Monster";
    default:
        return "Unknown";
    }
}

void Monster::SetStatus(monsterType type, const Player& player)
{
    Player& SetPlayer = const_cast<Player&>(player);

    int playerLevel = SetPlayer.GetLevel();

    int Hp = playerLevel * (20 + rand() % 11); // 레벨 * (20~30)
    int Attack = playerLevel * (5 + rand() % 6); // 레벨 * (5~10)

    // 현재 보스몬스터는 포함되어 있지 않음

    switch (type) {
    case MT_GOBLIN:
        _hp = Hp;
        _attack = Attack;
        _exp = 50;
        break;

    case MT_ORC:
        _hp = Hp;
        _attack = Attack;
        _exp = 50;
        break;

    case MT_TROLL:
        _hp = Hp;
        _attack = Attack;
        _exp = 50;
        break;

    case MT_BOSSMONSTER:
        _hp = playerLevel * 50;
        _attack = playerLevel * 50;
        _exp = 50;
        break;

    default:
        _hp = 0;
        _attack = 0;
        _exp = 0;
        break;
    }
}
