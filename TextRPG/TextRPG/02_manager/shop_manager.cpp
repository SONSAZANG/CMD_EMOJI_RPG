#include "shop_manager.h"
#include "../04_Util/util.h"
#include "../04_Util/gui.h"
#include "../03_ingame/weapons/weapon_shop.h"

void ShopManager::WelcomShop(Inventory* inventory)
{
	//int shopAction = 0;
	//bool exitFlag = false;
	//while (!exitFlag) {
	//	GUI::ClearUI();
	//	GUI::GoToXY(4, 22);
	//	uprint("상점에 오신걸 환영합니다.");
	//	GUI::GoToXY(4, 23);
	//	uprint("원하는 행동을 입력하세요.");
	//	GUI::GoToXY(4, 24);
	//	uprint("1. 구매 2. 판매 3. 강화 4. 나가기 ");
	//	shopAction = UTIL::IntegerVerify(shopAction, 1, 4);

	//	switch (shopAction) {
	//	case 1:
	//		BuyItem(inventory);
	//		break;
	//	case 2:
	//		SellItem(inventory);
	//		break;
	//	case 3:
	//		GUI::GoToXY(4, 28);
	//		uprintendl("a아직 준비되지 않았습니다.");
	//		Sleep(1000);
	//		GUI::GoToXY(4, 28);
	//		uprintendl("                            ");
	//		break;
	//	case 4:
	//		exitFlag = true;
	//		break;
	//	default:
	//		break;
	//	}
	//}

}

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

void ShopManager::BuyWeapon(Inventory* inventory)
{
	GUI::ClearUI();
	int buyChoice = 0;
	unique_ptr<WeaponShop> shop = make_unique<WeaponShop>();

	while (true) {
		shop->DisplayWeapons();

		GUI::GoToXY(4, 26);
		uprint("구매할 무기의 번호를 선택해주세요 : ");
		GUI::GoToXY(4, 27);
		UTIL::UPrint("->");
		buyChoice = UTIL::IntegerVerify(buyChoice, 1, shop->GetSize());

		shop->BuyWeapon(buyChoice, inventory);

		GUI::ClearUI();
		GUI::GoToXY(4, 26);
		uprintendl("구매 완료");
		break;
	}

	uprintendl("구매를 종료합니다");
}
