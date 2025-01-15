#pragma once
#include "../../01_core/scene_base.h"

class BossScene : public SceneBase
{
public:
	BossScene() {};
	virtual ~BossScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
};
