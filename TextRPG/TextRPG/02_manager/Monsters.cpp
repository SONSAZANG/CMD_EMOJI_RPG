#include "Monsters.h"
#include <cstdlib>
#include <ctime>

Monster::Monster(monsterType type, int hp, int attack, int exp)
    : _type(type), _hp(hp), _attack(attack), _exp(exp)
{
}

Monster Monster::RandomMonsterSpawn(const Player& player)
 {
    monsterType randomType = static_cast<monsterType>(1 + rand() % 3);

    Monster monster(randomType, 0, 0, 0);
    monster.SetStatus(randomType, player);
    return monster;
}


string Monster::GetName() const
{
    if (!_title.empty())
    {
        return _title + " " + GetBaseName();
    }
    return GetBaseName();
}

const char* Monster::GetBaseName() const
{
    switch (_type)
    {
    case MT_GOBLIN:
        return "Goblin";
    case MT_ORC:
        return "Orc";
    case MT_TROLL:
        return "Troll";
    default:
        return "Unknown";
    }
}

BossMonster::BossMonster(const Player& player)
    : Monster(MT_BOSSMONSTER, player.GetLevel() * 50, player.GetLevel() * 50, 1000) // 체력, 공격력, 경험치 설정
{
}

void BossMonster::DisplayBoss() const
{
    cout << u8"-------------------------" << endl;
    cout << u8"보스 체력: " << GetHp() << endl;
    cout << u8"보스 공격력: " << GetAttack() << endl;
    cout << u8"경험치: " << GetExp() << endl;
    cout << u8"-------------------------" << endl;
}


void Monster::DisplayMonster() const
{
    cout << u8"-------------------------" << endl;
    cout << u8"몬스터 타입: " << GetName() << endl;
    cout << u8"몬스터 체력: " << GetHp() << endl;
    cout << u8"몬스터 공격력: " << GetAttack() << endl;
    cout << u8"경험치: " << GetExp() << endl;
    cout << u8"-------------------------" << endl;
}

bool Monster::IsDead() const
{
    if (_hp <= 0)
        return true; // 체력이 0 이하일 경우 true -> 사망
    else
        return false; // 체력이 0보다 클 경우 false -> 생존
}


void Monster::SetHp(int hp)
{
    _hp = hp;
}
void Monster::SetAttack(int attack)
{
    _attack = attack;
}
void Monster::SetTitle(const string& title)
{
    _title = title;
}


void Monster::SetStatus(monsterType type, const Player& player)
{
    Player& SetPlayer = const_cast<Player&>(player);

    int playerLevel = SetPlayer.GetLevel();

    int Hp = playerLevel * (20 + rand() % 11); // 레벨 * (20~30)
    int Attack = playerLevel * (5 + rand() % 6); // 레벨 * (5~10)

    switch (type)
    {
    case MT_GOBLIN:
        SetHp(Hp);
        SetAttack(Attack);
        _exp = 50;
        break;

    case MT_ORC:
        SetHp(Hp);
        SetAttack(Attack);
        _exp = 50;
        break;

    case MT_TROLL:
        SetHp(Hp);
        SetAttack(Attack);
        _exp = 50;
        break;

    default:
        SetHp(0);
        SetAttack(0);
        _exp = 0;
        break;
    }

    const int maxAttack = playerLevel * 10;
    if (Attack == maxAttack)
    {
        SetTitle(u8" 불타는 ");
    }

}
