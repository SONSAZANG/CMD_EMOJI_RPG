#include "shop.h"
#include "../04_Util/gui.h"


void Shop::DisplayItems()
{
	if (!availableItems.empty()) {
		GUI::ClearUI();
		GUI::GoToXY(4, 21);
		uprint("상점 아이템 목록");
		for (int i = 0; i < availableItems.size(); ++i)
		{
			GUI::GoToXY(4, 22 + i);
			cout << i + 1 << ". " << availableItems[i]->GetName() << " "
				<< "<" << availableItems[i]->GetPrice() << ustring("골드") << "> ";
			availableItems[i]->GetDescription();
			
		}
	}
}

bool Shop::CanBuy(int index, Inventory* inventory) {
	return availableItems[index]->GetPrice() <= inventory->GetGold();
}

void Shop::BuyItem(int index, Inventory* inventory)
{
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
		inventory->DeleteFromInventory(index);

		GUI::GoToXY(106, 2);
		int intGold = inventory->GetGold();
		string gold = ustring("💰 골드 " + to_string(intGold) + "  ");
		uprint(gold);
	}
}
