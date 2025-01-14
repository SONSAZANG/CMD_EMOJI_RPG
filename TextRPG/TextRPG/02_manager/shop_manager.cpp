#include "shop_manager.h"
#include "../04_Util/util.h"

void ShopManager::WelcomShop(Inventory* inventory)
{
	int shopAction = 0;
	UTIL::UPrintEndl("상점에 오신 걸 환영합니다!");
	while (shopAction != 4) {
		UTIL::UPrint("1. 구매 2. 판매 3. 기타 4. 나가기 \n어떤 걸 할지 번호를 선택하세요. : ");
		cin >> shopAction;

		while (cin.fail() || shopAction < 0 || shopAction > 4) 
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			UTIL::UPrint("다시 입력하세요. ");
			cin >> shopAction;
		};

		switch (shopAction) {
			case 1:
				BuyItem(inventory);
				break;
			case 2:
				SellItem(inventory);
				break;
			case 3: 
				UTIL::UPrintEndl("아직 준비되지 않았습니다.");
				break;
			case 4:
				break;
			default:
				break;
		}
	}

	UTIL::UPrintEndl("감사합니다. 또 오세요!");
}

void ShopManager::BuyItem(Inventory* inventory)
{
	int buyChoice = 1;
	char keepBuying = 'Y';

	while (keepBuying == 'Y' || keepBuying == 'y') {
		inventory->DisplayGoldInfo();
		shop->DisplayItems();
		UTIL::UPrint("구매할 아이템의 번호를 선택해주세요 : ");
		cin >> buyChoice;
		while (cin.fail() || buyChoice < 1 || buyChoice > shop->GetItems().size())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			UTIL::UPrint("다시 입력하세요. ");
			cin >> buyChoice;
		};
		if (shop->CanBuy(buyChoice-1, inventory))
		{
			shop->BuyItem(buyChoice - 1, inventory);
			inventory->DisplayInventory();
		}
		else
		{
			UTIL::UPrintEndl("골드가 부족합니다.");
		}

		UTIL::UPrint("추가로 구매하시겠습니까? (Y/N) : ");
		cin >> keepBuying;
		while (cin.fail() || !(keepBuying == 'N' || keepBuying == 'n' || keepBuying == 'Y' || keepBuying == 'y'))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			UTIL::UPrint("다시 입력하세요. ");
			cin >> keepBuying;
		};
		
	}
	UTIL::UPrintEndl("구매를 종료합니다.");
}

void ShopManager::SellItem(Inventory* inventory)
{
	int sellChoice = 1;
	char keepSelling = 'Y';

	while (keepSelling == 'Y' || keepSelling == 'y') {
		inventory->DisplayGoldInfo();
		inventory->DisplayInventory();

		if (!inventory->IsInventoryEmpty()) 
		{
			UTIL::UPrint("판매할 아이템의 번호를 선택해주세요 : ");
			cin >> sellChoice;
			while (cin.fail() || sellChoice < 1 || sellChoice > inventory->GetInventorySize())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				UTIL::UPrint("다시 입력하세요. ");
				cin >> sellChoice;
			};
			shop->SellItem(sellChoice - 1, inventory);

			inventory->DisplayInventory();
		}
		UTIL::UPrint("추가로 판매하시겠습니까? (Y/N) : ");
		cin >> keepSelling;
		while (cin.fail() || !(keepSelling == 'N' || keepSelling == 'n' || keepSelling == 'Y' || keepSelling == 'y'))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			UTIL::UPrint("다시 입력하세요. ");
			cin >> keepSelling;
		};
	}

	uprintendl("판매를 종료합니다");
}
