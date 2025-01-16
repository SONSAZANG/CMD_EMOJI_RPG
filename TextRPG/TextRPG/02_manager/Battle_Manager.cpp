#pragma once
#include "battle_Manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "../04_Util/util.h"
#include "../04_Util/gui.h"
#include <thread>
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>

void BattleManager::Excute(Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	while (true)
	{
		SelectionBehavior(monster);

		if (monster.IsDead())
		{
			cout << monster.GetName() << UTIL::UString("사망!\n") << endl;
			break;
		}

		AttackTarget(false, monster);

		if (player.IsDead())
		{
			cout << player.GetName() << UTIL::UString("사망!\n") << endl;
			break;
		}
	}

	uprintendl("전투 종료");

	if (!player.IsDead())
	{
		uprintendl("승리!!");
		GetVictoryReWard();
		isWin = true;
	}
	else
	{
		uprintendl("패배");
		isWin = false;
	}	
}

bool BattleManager::GetIsWin() const
{
	return isWin;
}

void BattleManager::SelectionBehavior(Monster& monster)
{

	while (true) // 인풋 체크를 위한 반복문
	{
        string questionText1 = ustring("원하는 동작을 입력하세요.");
        string questionText2 = ustring("1. 공격하기 2. 아이템 사용 3. 도망가기");
        string questionText3 = ustring("");
        vector<string> questionTexts = { questionText1, questionText2, questionText3 };
        GUI::DrawQuestionText(questionTexts);

        GUI::GoToXY(8, 27);

		int selectNumber = UTIL::IntegerVerify(selectNumber, 1, 3);
        
		switch (selectNumber)
		{
		case 1:
			AttackTarget(true, monster);
			break;
		case 2:
			SelectionItem(monster); // 아이템 사용 후 재행동
			continue;
		case 3:
			PlayerManager::GetInstance()->GetPlayerInfo(); // 상태 확인 후 재행동
			continue;
		default:
			cout << u8"정의되지 않은 동작 " << endl;
			break;
		}

		break;
	}
}






void BattleManager::AttackTarget(const bool& playerFlag, Monster& monster)
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();

	auto attackAction = [](const string& attacker, auto& target,
		const auto getAttack, const auto getHp, const auto setHp) // 람다 함수 정의
	{
		int damage = getAttack();
		int newHp = getHp() - damage;
		newHp = (newHp < 0) ? 0 : newHp;
		setHp(newHp);

        cout << "" << endl;
        cout << "" << endl;
		cout << attacker << UTIL::UString("이 공격합니다.") << std::endl;
		PlayerManager::GetInstance()->GetPlayer().GetInventory()->UseWeapon();
		this_thread::sleep_for(chrono::seconds(1));

		cout << damage << UTIL::UString("의 데미지!!") << std::endl;
		this_thread::sleep_for(chrono::seconds(1));

		cout << target.GetName() << UTIL::UString(" 남은 체력: ") << newHp << std::endl;
	};

	if (playerFlag) // 공격하는 객체와 타겟을 결정하는 flag
	{
		attackAction(player.GetName(), monster,
			[&]() { return player.GetAttack(); },
			[&]() { return monster.GetHp(); },
			[&](int hp) { monster.SetHp(hp); });
	}
	else
	{
		attackAction(monster.GetName(), player,
			[&]() { return monster.GetAttack(); },
			[&]() { return player.GetHp(); },
			[&](int hp) { player.SetHp(hp); });
	}
}

void BattleManager::GetVictoryReWard()
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dice(10, 20);

	int gold = dice(gen); // 10 ~ 20 획득 골드 (과제 요구사항)

	player.GainExp(50); // 경험치 50 고정 획득 (과제 요구사항)
	player.GetInventory()->SetGold(player.GetInventory()->GetGold() + gold);

	player.GetInventory()->DisplayGoldInfo();
}

void BattleManager::SelectionItem(Monster& monster)
{
	PlayerManager::GetInstance()->GetPlayer().UseItem(monster);
}
void BattleManager::BossBattle(Player& player, BossMonster& bossMonster)
{
    srand(static_cast<unsigned>(time(0)));
    const int bossMaxHp = bossMonster.GetHp();
    double TimeLimit = 2.0;
    bool BossSpeech = false;

    while (bossMonster.GetHp() > 0 && player.GetHp() > 0)
    {
        if (bossMonster.GetHp() < bossMaxHp * 0.9 && !BossSpeech)
        {
            TimeLimit = 1.5;
            BossSpeech = true;

            uprintendl("-------------------------");
            uprintendl("Boss: 음... (타자) 좀 치잖아..?");
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            bossMonster.DisplayBossUI();
            uprintendl("Boss: 이제부터 전력을 다해야 할거야...");
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            bossMonster.DisplayBossUI();
            uprintendl("Boss: 이제부터 전력을 다해야 할거야... ♥");
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            bossMonster.DisplayBossUI();
        }

        int randSkill = rand() % 9;
        string skill;
        string evade;
        switch (randSkill)
        {
        case 0:
            skill = "Fire Wave";
            evade = "Dodge";
            break;
        case 1:
            skill = "Ice Spear";
            evade = "Shield";
            break;
        case 2:
            skill = "Thunder Burst";
            evade = "Counter";
            break;
        case 3:
            skill = "Shadow Strike";
            evade = "Roll";
            break;
        case 4:
            skill = "Earthquake";
            evade = "Jump";
            break;
        case 5:
            skill = "Poison Cloud";
            evade = "Mask";
            break;
        case 6:
            skill = "Wind Blade";
            evade = "Parry";
            break;
        case 7:
            skill = "Holy Smite";
            evade = "Pray";
            break;
        case 8:
            skill = "Dark Pulse";
            evade = "Focus";
            break;
        }

        DisplaySkillAnimation(skill);

        cout << "회피 방법 입력 (" << evade << "): ";
        string playerInput;
        auto start = chrono::high_resolution_clock::now();
        cin >> playerInput;
        auto end = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration<double>(end - start).count();

        if (elapsed > TimeLimit)
        {
            cout << "느려! 보스의 강력한 공격을 받았다!" << endl;
            int playerHp = player.GetHp() - bossMonster.GetAttack();
            player.SetHp(playerHp < 0 ? 0 : playerHp);

            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            bossMonster.DisplayBossUI();
        }
        else if (playerInput == evade)
        {
            cout << "성공적으로 회피했다! 보스에게 반격을 시도했다!" << endl;
            int bossHp = bossMonster.GetHp() - player.GetAttack();
            bossMonster.SetHp(bossHp < 0 ? 0 : bossHp);

            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            bossMonster.DisplayBossUI();
        }
        else
        {
            cout << "회피 실패! 보스의 강력한 공격을 받았다!" << endl;
            int playerHp = player.GetHp() - bossMonster.GetAttack();
            player.SetHp(playerHp < 0 ? 0 : playerHp);

            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            bossMonster.DisplayBossUI();
        }

        if (bossMonster.GetHp() <= 0)
        {
            cout << "이걸 이기네?" << endl;
            break;
        }
        if (player.GetHp() <= 0)
        {
            cout << "그 정도 타자 속도로는 내 반쪽이 될 자격이 없다.." << endl;
            break;
        }
    }
}



void BattleManager::DisplaySkillAnimation(const string& skillName)
{
    cout << "보스가 " << skillName << " 스킬을 사용합니다!" << endl;
    if (skillName == "Fire Wave")
    {
        cout << "🔥🔥🔥 불길이 퍼집니다! 🔥🔥🔥" << endl;
    }
    else if (skillName == "Ice Spear")
    {
        cout << "❄️❄️❄️ 얼음 창이 날아옵니다! ❄️❄️❄️" << endl;
    }
    else if (skillName == "Thunder Burst")
    {
        cout << "⚡⚡⚡ 천둥이 울립니다! ⚡⚡⚡" << endl;
    }
    else if (skillName == "Shadow Strike")
    {
        cout << "🌑🌑🌑 그림자가 다가옵니다! 🌑🌑🌑" << endl;
    }
    else if (skillName == "Earthquake")
    {
        cout << "🌍🌍🌍 대지가 흔들립니다! 🌍🌍🌍" << endl;
    }
    else if (skillName == "Poison Cloud")
    {
        cout << "☠️☠️☠️ 독 구름이 퍼집니다! ☠️☠️☠️" << endl;
    }
    else if (skillName == "Wind Blade")
    {
        cout << "💨💨💨 바람의 칼날이 휘몰아칩니다! 💨💨💨" << endl;
    }
    else if (skillName == "Holy Smite")
    {
        cout << "✨✨✨ 신성한 빛이 내려옵니다! ✨✨✨" << endl;
    }
    else if (skillName == "Dark Pulse")
    {
        cout << "🌌🌌🌌 어둠의 파동이 느껴집니다! 🌌🌌🌌" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
}