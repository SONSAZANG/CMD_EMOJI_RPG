#include "battle_Manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "Monsters.h"

void BattleManager::Excute() // 파라미터로 몬스터 받고 처리할 생각
{
	bool temp_IsDead = false; // 임시
	//Player& player = PlayerManager::GetInstance()->GetPlayer();

	while (!temp_IsDead)
	{	
		SelectionBehavior(); // 플레이어 행동 선택
		temp_IsDead = true; // 임시, 몬스터 죽음 또는 플레이어 죽음 판단 후 빠져나가기
		// 몬스터가 살아있으면 몬스터가 공격
	}
}

void BattleManager::SelectionBehavior()
{
	while (true)
	{
		std::cout << "1. 공격	" << "2. 아이템 사용 ";
		int selectNumber = 0;
		std::cin >> selectNumber;
		if (std::cin.fail() || !(selectNumber > 0) || selectNumber > 2) // 예외 처리
		{
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "다시 입력하세요." << std::endl;
			continue;
		};

		if (selectNumber == 1)
		{
			// 플레이어가 대상을 공격 AttackTarget(플레이어, 몬스터);
			int temp_MonsterHP = 100;
			AttackTarget(); // 임시 코드
		}
		else
		{
			
			continue;
		}
		break;
	}
}

void BattleManager::AttackTarget() // 플레이어 몬스터 구현 필요
{	
	std::cout << "공격 !!";
}