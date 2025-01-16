#include "shop.h"
#include "../04_Util/gui.h"


void Shop::DisplayItems()
{
	if (!availableItems.empty()) {
		GUI::ClearUI();
		GUI::GoToXY(4, 21);
		uprint("상점 아이템 목록");
		int j = 0;
		for (int i = 0; i < availableItems.size(); ++i)
		{
			if (i != 0 && i % 3 == 0)
				++j;
			GUI::GoToXY(4 + j * 40, 22 + (i % 3));
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

	GUI::DrawGoldInfo();
}

void Shop::SellItem(int index, Inventory* inventory)
{
	if (!inventory->IsInventoryEmpty())
	{
		int sellPrice = (int)(inventory->GetInventoryItem(index)->GetPrice() * 0.6);
		inventory->SetGold(inventory->GetGold() + sellPrice);
		inventory->DeleteFromInventory(index);

		GUI::DrawGoldInfo();
	}
}

int Shop::GetShopItemSize()
{
	return (int)availableItems.size();
}
