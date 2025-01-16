#include "shop_manager.h"
#include "../04_Util/gui.h"

void ShopManager::BuyItem(Inventory* inventory)
{
	int buyChoice = 0;
	char answer[] = { 'Y','y','N','n' };
	int answer_size = sizeof(answer) / sizeof(answer[0]);

	while (true)
	{
		GUI::ClearUI();
		shop->DisplayItems();

		GUI::GoToXY(4, 26);
		uprint("구매할 아이템의 번호를 선택해주세요. ");
		GUI::GoToXY(4, 27);
		UTIL::UPrint("->");
		buyChoice = UTIL::IntegerVerify(buyChoice, 1, 3); // 임시로 끝 파라미터 3 입력, 아이템 종류 개수 넣으면 될 같음

		GUI::ClearUI();
		if (shop->CanBuy(buyChoice - 1, inventory))
		{
			shop->BuyItem(buyChoice - 1, inventory);
			inventory->DisplayInventory();
		}
		else
		{
			GUI::GoToXY(4, 22);
			UTIL::UPrintEndl("골드가 부족합니다.");
		}


		GUI::GoToXY(4, 26);
		uprint("추가로 구매하시겠습니까? (Y/N)");
		GUI::GoToXY(4, 27);
		UTIL::UPrint("->");

		char input = UTIL::CharVerify(answer, answer_size);

		if (input == 'n' || input == 'N')
			break;
	}
}

void ShopManager::SellItem(Inventory* inventory)
{
	int sellChoice = 0;
	char answer[] = { 'Y','y','N','n' };
	int answer_size = sizeof(answer) / sizeof(answer[0]);

	while (true) {
		GUI::ClearUI();
		inventory->DisplayInventory();

		if (!inventory->IsInventoryEmpty())
		{
			GUI::ClearUI();
			inventory->DisplayInventory();
			GUI::GoToXY(4, 26);
			uprint("판매할 아이템의 번호를 선택해주세요.");
			GUI::GoToXY(4, 27);
			UTIL::UPrint("->");
			sellChoice = UTIL::IntegerVerify(sellChoice, 1, inventory->GetInventorySize());
			shop->SellItem(sellChoice - 1, inventory);
			GUI::ClearUI();
			inventory->DisplayInventory();
		}
		

		GUI::GoToXY(4, 26);
		uprint("추가로 판매하시겠습니까? (Y/N)");
		GUI::GoToXY(4, 27);
		UTIL::UPrint("->");
		char input = UTIL::CharVerify(answer, answer_size);

		if (input == 'n' || input == 'N')
			break;
	}
}
