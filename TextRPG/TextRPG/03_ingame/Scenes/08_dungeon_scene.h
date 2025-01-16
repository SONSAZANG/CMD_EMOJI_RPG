#pragma once
#include "../../01_core/scene_base.h"
#include "../../02_manager/Monsters.h"
#include "../../03_ingame/Stage.h"

class DungeonScene : public SceneBase
{
public:
	DungeonScene() {};
	virtual ~DungeonScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
	void DrawBossAttack();
	void DrawStartText();

	Stage _currentStage;
};
