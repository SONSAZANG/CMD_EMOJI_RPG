#include "Monsters.h"
#include "../04_Util/util.h"
#include <cstdlib>
#include <ctime>

Monster::Monster(monsterType type, int hp, int attack, int exp)
    : _type(type), _hp(hp), _attack(attack), _exp(exp)
{
}

Monster Monster::SelectMonster(const Player& player)
 {
    int choice;
    cin >> choice;

    if (choice == 4)
    {
        if (player.GetLevel() < 10)
        {
            cout << "감히 접근할 수 없습니다!" << endl;
            return SelectMonster(player);
        }
        else
        {
            return BossMonster(player);
        }
    }
    else
    {
        Monster selectedMonster(MT_SPIDER, 0, 0, 0);
        switch (choice)
        {
        case 1:
            selectedMonster.SetStatus(MT_SPIDER, player);
            break;
        case 2:
            selectedMonster.SetStatus(MT_ORC, player);
            break;
        case 3:
            selectedMonster.SetStatus(MT_TROLL, player);
            break;
        default:
            cout << "잘못된 선택입니다." << endl;
            SelectMonster(player);
        }
        return selectedMonster;
    }
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
    case MT_SPIDER:
        return "Spider";
    case MT_ORC:
        return "Orc";
    case MT_TROLL:
        return "Troll";
    case MT_BOSSMONSTER:
        return "The Boss";
    default:
        return "Unknown";
    }
}

BossMonster::BossMonster(const Player& player)
    : Monster(MT_BOSSMONSTER, player.GetLevel() * 50, player.GetLevel() * 50, 1000) // 체력, 공격력, 경험치 설정
{
    SetType(MT_BOSSMONSTER);
}

void BossMonster::DisplayBossUI() const
{
    uprintendl("-------------------------");
    cout << ustring("보스 체력: ") << GetHp() << endl;
    cout << ustring("보스 공격력: ") << GetAttack() << endl;
    uprintendl("-------------------------");
}

void Monster::DisplayMonster() const
{
    uprintendl("-------------------------");
    cout << ustring("몬스터 이름: ") << ustring(GetName()) << endl;
    cout << ustring("몬스터 체력: ") << GetHp() << endl;
    cout << ustring("몬스터 공격력: ") << GetAttack() << endl;
    cout << ustring("경험치: ") << GetExp() << endl;
    uprintendl("-------------------------");

}

bool Monster::IsDead() const
{
    if (_hp <= 0)
        return true;
    else
        return false;
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

    int Hp = playerLevel * (20 + rand() % 11);
    int Attack = playerLevel * (5 + rand() % 6);

    switch (type)
    {
    case MT_SPIDER:
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
        SetTitle(ustring(" 불타는 "));
    }

}
