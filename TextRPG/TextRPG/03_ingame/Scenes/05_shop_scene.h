#pragma once
#include "../../01_core/scene_base.h"

class ShopScene : public SceneBase
{
public:
	ShopScene() {};
	virtual ~ShopScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
};
