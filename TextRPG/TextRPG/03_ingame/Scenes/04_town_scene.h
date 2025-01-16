#pragma once
#include "../../01_core/scene_base.h"
#include <string>

using namespace std;

class TownScene : public SceneBase
{
public:
	TownScene() {};
	virtual ~TownScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
	void DrawBottomLayout();
	void HandleInvalidJobSelection(string message);
};
