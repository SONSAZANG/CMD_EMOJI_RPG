#include "shop_manager.h"
#include "../04_Util/util.h"

void ShopManager::WelcomShop(Inventory* inventory)
{
	int shopAction = 0;
	bool exitFlag = false;
	uprintendl("상점에 오신 걸 환영합니다!");
	while (!exitFlag) {
		uprint("1. 구매 2. 판매 3. 기타 4. 나가기 \n어떤 걸 할지 번호를 선택하세요. : ");
		shopAction = UTIL::IntegerVerify(shopAction, 1, 4);

		switch (shopAction) {
		case 1:
			BuyItem(inventory);
			break;
		case 2:
			SellItem(inventory);
			break;
		case 3:
			uprintendl("아직 준비되지 않았습니다.");
			break;
		case 4:
			exitFlag = true;
			break;
		default:
			break;
		}
	}

	UTIL::UPrintEndl("감사합니다. 또 오세요!");
}

void ShopManager::BuyItem(Inventory* inventory)
{
	int buyChoice = 0;
	char answer[] = { 'Y','y','N','n' };
	int answer_size = sizeof(answer) / sizeof(answer[0]);

	while (true)
	{
		inventory->DisplayGoldInfo();
		shop->DisplayItems();

		uprint("구매할 아이템의 번호를 선택해주세요 : ");
		buyChoice = UTIL::IntegerVerify(buyChoice, 1, 3); // 임시로 끝 파라미터 3 입력, 아이템 종류 개수 넣으면 될 같음

		if (shop->CanBuy(buyChoice - 1, inventory))
		{
			shop->BuyItem(buyChoice - 1, inventory);
			inventory->DisplayInventory();
		}
		else
		{
			UTIL::UPrintEndl("골드가 부족합니다.");
		}

		uprintendl("추가로 구매하시겠습니까? (Y/N) : ");

		char input = UTIL::CharVerify(answer, answer_size);

		if (input == 'n' || input == 'N')	
			break;
	}
	UTIL::UPrintEndl("구매를 종료합니다.");
}

void ShopManager::SellItem(Inventory* inventory)
{
	int sellChoice = 0;
	char answer[] = { 'Y','y','N','n' };
	int answer_size = sizeof(answer) / sizeof(answer[0]);

	while (true) {
		inventory->DisplayGoldInfo();
		inventory->DisplayInventory();

		if (!inventory->IsInventoryEmpty())
		{
			cout << u8"판매할 아이템의 번호를 선택해주세요 : ";
			sellChoice = UTIL::IntegerVerify(sellChoice, 1, inventory->GetInventorySize());

			shop->SellItem(sellChoice - 1, inventory);

			inventory->DisplayInventory();
		}

		cout << u8"추가로 판매하시겠습니까? (Y/N) : ";
		char input = UTIL::CharVerify(answer, answer_size);

		if (input == 'n' || input == 'N')
			break;
	}

	uprintendl("판매를 종료합니다");
}
