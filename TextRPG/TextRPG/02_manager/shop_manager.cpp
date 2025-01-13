#include "shop_manager.h"

void ShopManager::WelcomShop(Inventory* inventory)
{
	int shopAction = 0;
	cout << "상점에 오신 걸 환영합니다!" << endl;
	while (shopAction != 4) {
		cout << "1. 구매 2. 판매 3. 기타 4. 나가기 \n어떤 걸 할지 번호를 선택하세요. : ";
		cin >> shopAction;

		if (cin.fail() || shopAction < 0 || shopAction > 4) 
		{
			cout << std::endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n다시 입력하세요.\n" << endl;
			continue;
		};

		switch (shopAction) {
			case 1:
				BuyItem(inventory);
				break;
			case 2:
				SellItem(inventory);
				break;
			case 3: 
				cout << "\n아직 준비되지 않았습니다.\n" << endl;
				break;
			case 4:
				break;
			default:
				cout << "\n잘못된 번호를 입력했습니다.\n" << endl;
		}
	}

	cout << "감사합니다. 또 오세요!" << endl;
}

void ShopManager::BuyItem(Inventory* inventory)
{
	int buyChoice = 1;
	char keepBuying = 'Y';

	while (keepBuying == 'Y' || keepBuying == 'y') {
		cout << endl;
		inventory->DisplayGoldInfo();
		shop->DisplayItems();
		cout << endl;

		cout << "구매할 아이템의 번호를 선택해주세요 : "; 
		cin >> buyChoice;
		while (cin.fail() || buyChoice < 1 || buyChoice > shop->GetItems().size())
		{
			cout << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n다시 입력하세요.\n" << endl;
			cin >> buyChoice;
		};
		if (shop->CanBuy(buyChoice-1, inventory))
		{
			shop->BuyItem(buyChoice - 1, inventory);

			cout << endl;
			inventory->DisplayInventory();
			cout << endl;
		}
		else
		{
			cout << "골드가 부족합니다." << endl;
		}

		cout << "추가로 구매하시겠습니까? (Y/N) : ";
		cin >> keepBuying;
		while (cin.fail() || !(keepBuying == 'N' || keepBuying == 'n' || keepBuying == 'Y' || keepBuying == 'y'))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n다시 입력하세요.\n" << endl;
			cin >> keepBuying;
		};
		
	}

	cout << "구매를 종료합니다\n" << endl;
}

void ShopManager::SellItem(Inventory* inventory)
{
	int sellChoice = 1;
	char keepSelling = 'Y';

	while (keepSelling == 'Y' || keepSelling == 'y') {
		cout << endl;
		inventory->DisplayGoldInfo();
		inventory->DisplayInventory();
		cout << endl;

		if (!inventory->IsInventoryEmpty()) 
		{
			cout << "판매할 아이템의 번호를 선택해주세요 : "; //TODO: 예외처리(숫자 외 다른 타입, 범위 외 입력 시)
			cin >> sellChoice;
			while (cin.fail() || sellChoice < 1 || sellChoice > inventory->GetInventorySize())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\n다시 입력하세요.\n" << endl;
				cin >> sellChoice;
			};
			shop->SellItem(sellChoice - 1, inventory);

			cout << endl;
			inventory->DisplayInventory();
			cout << endl;
		}

		cout << "추가로 판매하시겠습니까? (Y/N) : ";
		cin >> keepSelling;
		while (cin.fail() || !(keepSelling == 'N' || keepSelling == 'n' || keepSelling == 'Y' || keepSelling == 'y'))
		{
			cout << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n다시 입력하세요.\n" << endl;
			cin >> keepSelling;
		};
	}

	cout << "판매를 종료합니다\n" << endl;
}
