#pragma once
#include "../../01_core/scene_base.h"
#include <string>

using namespace std;

class JobCenterScene : public SceneBase
{
public:
	JobCenterScene() {};
	virtual ~JobCenterScene() {};

	virtual void Init() override;

private:
	void DrawMainLayout();
	void SelectCommand();
	void ChangePlayerJob(string job, string jobName);
};
