#pragma once
#include "../../01_core/scene_base.h"

class StartScene : public SceneBase
{
public:
	StartScene() {};
	virtual ~StartScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void HandleStartInput();
};