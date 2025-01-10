#include "Battle_Manager.h"

void BattleManager::Excute()
{
	while (true)
	{	
		// 몬스터 스폰
		SelectionBehavior();
		// 몬스터 죽음 판단 isDead ?
		// isDead =false - AttackTarget(몬스터, 플레이어), 반복
		// isDead =true - 스테이지 카운트 ++, 골드 경험치 획득, 다음 스테이지 이동 또는 상점 결정 후 break
	}
}

void BattleManager::SelectionBehavior()
{
	std::cout << "1. 공격	" << "2. 아이템 사용 ";
	
	int input = 0;
	std::cin >> input;
	while (std::cin.fail() || !(input > 0) || input > 2)
	{
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "다시 입력하세요." << std::endl;
		std::cin >> input;
	};

	if (input == 1)
	{
		// 플레이어가 대상을 공격 AttackTarget(플레이어, 몬스터);
		AttackTarget();
	}
	else
	{
		// 보유 아이템 선택
		UseItem();
	}
}

void BattleManager::AttackTarget()
{
	std::cout << "공격 !!";
	//몬스터와 플레이어 정보를 받아와서 데미지 계산 처리
}

void BattleManager::UseItem()
{
	//아이템 정보 가져와서 플레이어 적용
	std::cout << "아이템 사용";
}

void BattleManager::MoveStage() const
{
	int input = 0;
	std::cin >> input;
	while (std::cin.fail() || !(input > 0) || input > 2)
	{	
		std::cout << std::endl;
		std::cout << "다시 입력하세요." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> input;
	};
}