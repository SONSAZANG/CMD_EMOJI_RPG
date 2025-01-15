#include "shop.h"
#include "../04_Util/gui.h"


void Shop::DisplayItems()
{
	if (!availableItems.empty()) {
		GUI::ClearUI();
		GUI::GoToXY(4, 21);
		uprint("상점 아이템 목록:");
		for (int i = 0; i < availableItems.size(); ++i)
		{
			GUI::GoToXY(4, 22 + i);
			cout << i + 1 << ". " << availableItems[i]->GetName()
				<< "(" << " +" << availableItems[i]->GetAmount() << ") : "
				<< availableItems[i]->GetPrice() << ustring("골드") << endl;
		}
	}
}

bool Shop::CanBuy(int index, Inventory* inventory) {
	return availableItems[index]->GetPrice() <= inventory->GetGold();
}

void Shop::BuyItem(int index, Inventory* inventory)
{
	GUI::GoToXY(4, 22);
	cout << availableItems[index]->GetName() << ustring("을 구매했습니다.") << endl;
	inventory->SetGold(inventory->GetGold() - availableItems[index]->GetPrice());
	inventory->AddToInventory(availableItems[index]);

	GUI::GoToXY(106, 2);
	int intGold = inventory->GetGold();
	string gold = ustring("💰 골드 " + to_string(intGold) + "  ");
	uprint(gold);
}

void Shop::SellItem(int index, Inventory* inventory)
{
	if (!inventory->IsInventoryEmpty())
	{
		int sellPrice = (int)(inventory->GetInventoryItem(index)->GetPrice() * 0.6);
		GUI::GoToXY(4, 22);
		cout << inventory->GetInventoryItem(index)->GetName() << ustring("을 판매했습니다.") << endl;
		GUI::GoToXY(4, 23);
		cout << sellPrice << ustring("골드를 얻어 현재");
		inventory->SetGold(inventory->GetGold() + sellPrice);
		cout << inventory->GetGold() << ustring("골드가 되었습니다.") << endl;
		inventory->DeleteFromInventory(index);

		GUI::GoToXY(106, 2);
		int intGold = inventory->GetGold();
		string gold = ustring("💰 골드 " + to_string(intGold) + "  ");
		uprint(gold);
	}
}
