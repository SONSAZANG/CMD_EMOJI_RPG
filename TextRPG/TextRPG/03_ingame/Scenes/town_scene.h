#pragma once
#include "../../01_core/scene_base.h"

class TownScene : public SceneBase
{
public:
	TownScene();
	virtual ~TownScene();

	virtual void Init() override;
	virtual void Clear() override;
};
