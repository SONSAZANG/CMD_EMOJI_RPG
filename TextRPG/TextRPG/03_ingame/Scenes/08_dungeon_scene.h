#pragma once
#include "../../01_core/scene_base.h"
#include "../../02_manager/Monsters.h"

class DungeonScene : public SceneBase
{
public:
	DungeonScene() {};
	virtual ~DungeonScene() {};

	virtual void Init() override;

	void SelectCommand(Monster& monster);

private:
	void DrawMainLayout();
};
