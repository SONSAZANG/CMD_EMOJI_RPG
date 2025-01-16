#pragma once
#include "../../01_core/scene_base.h"
#include "../../02_manager/shop_manager.h"


class ShopScene : public SceneBase
{
public:
	ShopScene() {};
	virtual ~ShopScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
	void DrawStartText();
	void DrawGold();
	void DrawBuy(Inventory* inven);
	void DrawSell(Inventory* inven);
	void DrawEnhance(Inventory* inven);
	void DrawWeaponBuy(Inventory* inven);
};