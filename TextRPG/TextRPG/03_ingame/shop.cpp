#include "shop.h"
#include "../04_Util/util.h"

void Shop::DisplayItems()
{
	if (!availableItems.empty()) {
		uprintendl("상점 아이템 목록:");
		for (int i = 0; i < availableItems.size(); ++i) 
		{
			cout << i + 1 << ". " << availableItems[i]->GetName()
			<<"(" << " +" << availableItems[i]->GetAmount() << ") : "
			<< availableItems[i]->GetPrice() << ustring("골드") << endl;
		}
	}
}

bool Shop::CanBuy(int index, Inventory* inventory) {
	return availableItems[index]->GetPrice() <= inventory->GetGold();
}

void Shop::BuyItem(int index, Inventory* inventory)
{
	cout << availableItems[index]->GetName() << ustring("을 구매했습니다.") << endl;
	inventory->SetGold(inventory->GetGold() - availableItems[index]->GetPrice());
	inventory->AddToInventory(availableItems[index]);
}

void Shop::SellItem(int index, Inventory* inventory)
{
	if (!inventory->IsInventoryEmpty()) 
	{
		int sellPrice = (int)(inventory->GetInventoryItem(index)->GetPrice() * 0.6);
		cout << inventory->GetInventoryItem(index)->GetName() << ustring("을 판매했습니다.") << endl;
		cout << sellPrice << ustring("골드를 얻어 현재");
		inventory->SetGold(inventory->GetGold()+sellPrice);
		cout << inventory->GetGold() << ustring("골드가 되었습니다.") << endl;
		inventory->DeleteFromInventory(index);
	}
}
