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
			SelectionItem();
			continue;
		}
		break;
	}
}

void BattleManager::AttackTarget() // 플레이어 몬스터 구현 필요
{	
	std::cout << "공격 !!";
}

void BattleManager::SelectionItem() // 전투 시스템에 아이템 사용 로직?
{
	Player& player = PlayerManager::GetInstance()->GetPlayer();
	player.GetInventory()->DisplayInventory();

	if (player.GetInventory()->IsInventoryEmpty()) // 인벤토리 비었을 때 빠져나오기
	{
		return;
	}

	while (true)
	{
		int useIndex = 0;
		cout << "사용할 아이템의 번호를 입력해주세요.";
		cin >> useIndex;
		if (std::cin.fail() || !(useIndex > 0) || useIndex > 2)
		{
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "다시 입력하세요." << std::endl;
			continue;
		};

		if (player.GetInventory()->GetInventoryItem(useIndex - 1)->GetItemType() == ITEM_HealthPotion)
		{
			cout << "Hp " << player.GetInventory()->GetInventoryItem(useIndex - 1)->GetAmount() << "를 회복했습니다. ";
			player.UseItem(useIndex - 1);
			cout << "현재 Hp: " << player.GetHp() << endl;
		}
		else
		{
			cout << "Attack " << player.GetInventory()->GetInventoryItem(useIndex - 1)->GetAmount() << "가 증가했습니다. ";
			player.UseItem(useIndex - 1);
			cout << "현재 Attack: " << player.GetAttack() << endl;
		}

		break;
	}
}