#pragma once
#include "../../01_core/scene_base.h"

class PlayerSettingScene : public SceneBase
{
public:
	PlayerSettingScene() {};
	virtual ~PlayerSettingScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
};