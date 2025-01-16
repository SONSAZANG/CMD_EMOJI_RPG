#include "boss_monster.h"
#include "../04_Util/gui.h"
#include "../04_Util/util.h"
#include "../03_ingame/boss_skill.h"
#include <cstdlib>
#include <ctime>
#include <chrono>

BossMonster::BossMonster(const Player& player)
    : Monster(MT_BOSSMONSTER, player.GetLevel() * 50, player.GetLevel() * 50, 1000) // 체력, 공격력, 경험치 설정
{
    SetType(MT_BOSSMONSTER);
}

void BossMonster::BossAttack()
{
    // 버서커 상태 확인 후 하드모드 적용
    if (IsBerserk()) BossHardMode();

    BossSkill randSkill = GetRandomSkill((EBossSkillType)(rand() % 10));

    string skillText = ustring(randSkill.skillText);
    
    // "회피 방법 입력 (" << {evadeText} << "): "
    string evadeText = ustring(randSkill.evadeText);

    double elapsed = getElapsed();

    // 입력 속도가 늦었으면 끝
    if (elapsed > attackTimeLimit)
    {
        uprint("느려! 보스의 강력한 공격을 받았다!");
        PlayerManager::GetInstance()->GetPlayer().SetDamage(GetAttack());

        Sleep(1000);
    }

    // 입력 텍스트를 성공하면
    if (inputText == evadeText)
    {
        uprint("성공적으로 회피했다! 보스에게 반격을 시도했다!");
        SetDamage(PlayerManager::GetInstance()->GetPlayer().GetAttack());

        Sleep(1000);
    }
    else
    {
        uprint("회피 실패! 보스의 강력한 공격을 받았다!");
        PlayerManager::GetInstance()->GetPlayer().SetDamage(GetAttack());

        Sleep(1000);
    }
}



double BossMonster::getElapsed()
{
    auto start = chrono::high_resolution_clock::now();
    cin >> inputText;
    auto end = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration<double>(end - start).count();
    return elapsed;
}

void BossMonster::CheckStatus()
{
    // 보스 죽었으면
    if (IsDead())
    {
        uprint("이걸 이기네?");
    }
    
    // 플레이어 죽었으면
    bool isPlayerDead = PlayerManager::GetInstance()->GetPlayer().IsDead();
    if (isPlayerDead)
    {
        uprint("그 정도 타자 속도로는 내 반쪽이 될 자격이 없다..");
    }
}

void BossMonster::BossHardMode()
{
    uprint("음... (타자) 좀 치잖아..?");
    uprint("이제부터 전력을 다해야 할거야...");
    
    attackTimeLimit = 1.5;
}

BossSkill BossMonster::GetRandomSkill(EBossSkillType skillType)
{
    switch (skillType)
    {
    case FIRE:
        return BossSkill(FIRE, "Fire Wave", "Dodge", "🔥🔥🔥 불길이 퍼집니다! 🔥🔥🔥");
        break;
    case ICE:
        return BossSkill(ICE, "Ice Spear", "Shield", "❄️❄️❄️ 얼음 창이 날아옵니다! ❄️❄️❄️");
        break;
    case THUNDER:
        return BossSkill(THUNDER, "Thunder Burst", "Counter", "⚡⚡⚡ 천둥이 울립니다! ⚡⚡⚡");
        break;
    case SHADOW:
        return BossSkill(SHADOW, "Shadow Strike", "Roll", "🌑🌑🌑 그림자가 다가옵니다! 🌑🌑🌑");
        break;
    case EARTHQUAKE:
        return BossSkill(EARTHQUAKE, "Earthquake", "Jump", "🌍🌍🌍 대지가 흔들립니다! 🌍🌍🌍");
        break;
    case POISON:
        return BossSkill(POISON, "Poison Cloud", "Mask", "☠️☠️☠️ 독 구름이 퍼집니다! ☠️☠️☠️");
        break;
    case WIND:
        return BossSkill(WIND, "Wind Blade", "Parry", "💨💨💨 바람의 칼날이 휘몰아칩니다! 💨💨💨");
        break;
    case HOLY:
        return BossSkill(HOLY, "Holy Smite", "Pray", "✨✨✨ 신성한 빛이 내려옵니다! ✨✨✨");
        break;
    case DARK:
        return BossSkill(DARK, "Dark Pulse", "Focus", "🌌🌌🌌 어둠의 파동이 느껴집니다! 🌌🌌🌌");
        break;
    }
}


