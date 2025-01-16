#include "Monsters.h"
#include "../04_Util/util.h"
#include "../02_manager/player_manager.h"
#include "../03_ingame/boss_monster.h"
#include <cstdlib>
#include <ctime>

Monster::Monster(monsterType type, int hp, int attack, int exp)
    : _type(type), _hp(hp), _maxHp(hp), _attack(attack), _exp(exp)
{
}


int Monster::GetMaxHp() const {
    return _maxHp;
}

void Monster::SetMaxHp(int maxHp) {
    _maxHp = maxHp;
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
            selectedMonster.SetStatus(MT_SPIDER);
            break;
        case 2:
            selectedMonster.SetStatus(MT_ORC);
            break;
        case 3:
            selectedMonster.SetStatus(MT_TROLL);
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
        return "🐉버그왕 흑염룡🐉";
    default:
        return "Unknown";
    }
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
bool Monster::IsBoss() const
{
    return _type == MT_BOSSMONSTER ? true : false;
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
void Monster::SetStatus(monsterType type)
{
    int playerLevel = PlayerManager::GetInstance()->GetPlayer().GetLevel();
    int Hp = playerLevel * (20 + rand() % 11);
    int Attack = playerLevel * (5 + rand() % 6);

    SetType(type);
    SetHp(Hp);
    SetMaxHp(Hp);
    SetAttack(Attack);

    switch (type)
    {
    case MT_SPIDER:
        _exp = 50;
        break;

    case MT_ORC:
        _exp = 50;
        break;

    case MT_TROLL:
        _exp = 50;
        break;

    case MT_BOSSMONSTER:
        _exp = 50;
        break;

    default:
        SetHp(0);
        SetAttack(0);
        _exp = 0;
        break;
    }

    const int maxAttack = playerLevel * 10;
    if (Attack == maxAttack && type != MT_BOSSMONSTER)
    {
        SetTitle(ustring("[🔥불타는]"));
    }
}

