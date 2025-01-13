#pragma once
#include "../../01_core/scene_base.h"

class LoadingScene : public SceneBase
{
public:
	LoadingScene() {};
	virtual ~LoadingScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
};