#include "shop_manager.h"
#include "../04_Util/input_verify.h"

void ShopManager::WelcomShop(Inventory* inventory)
{
	int shopAction = 0;
	bool exitFlag = false;
	cout << u8"상점에 오신 걸 환영합니다!" << endl;
	while (!exitFlag) {
		cout << u8"1. 구매 2. 판매 3. 기타 4. 나가기 \n어떤 걸 할지 번호를 선택하세요. : ";
		shopAction = InputVerify::IntegerVerify(shopAction, 1, 4);

		switch (shopAction) {
		case 1:
			BuyItem(inventory);
			break;
		case 2:
			SellItem(inventory);
			break;
		case 3:
			cout << u8"아직 준비되지 않았습니다." << endl;
			break;
		case 4:
			exitFlag = true;
			break;
		default:
			break;
		}
	}

	cout << u8"감사합니다. 또 오세요!" << endl;
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

		cout << u8"구매할 아이템의 번호를 선택해주세요 : ";
		buyChoice = InputVerify::IntegerVerify(buyChoice, 1, 3); // 임시로 끝 파라미터 3 입력, 아이템 종류 개수 넣으면 될 같음

		if (shop->CanBuy(buyChoice - 1, inventory))
		{
			shop->BuyItem(buyChoice - 1, inventory);
			inventory->DisplayInventory();
		}
		else
		{
			cout << u8"골드가 부족합니다." << endl;
		}

		cout << u8"추가로 구매하시겠습니까? (Y/N) : ";

		char input = InputVerify::CharVerify(answer, answer_size);

		if (input == 'n' || input == 'N')	
			break;
	}

	cout << u8"구매를 종료합니다." << endl;
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
			sellChoice = InputVerify::IntegerVerify(sellChoice, 1, inventory->GetInventorySize());

			shop->SellItem(sellChoice - 1, inventory);

			inventory->DisplayInventory();
		}

		cout << u8"추가로 판매하시겠습니까? (Y/N) : ";
		char input = InputVerify::CharVerify(answer, answer_size);

		if (input == 'n' || input == 'N')
			break;
	}

	cout << u8"판매를 종료합니다" << endl;
}
