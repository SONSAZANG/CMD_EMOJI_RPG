#pragma once
#include "../../01_core/scene_base.h"

class EndScene : public SceneBase
{
public:
	EndScene() {};
	virtual ~EndScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
};
