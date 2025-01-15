#pragma once
#include "../01_core/singleton_base.h"
#include "../03_ingame/stage.h"
class StageManager : public SingletonBase<StageManager> {

	friend class SingletonBase<StageManager>;

private:
	StageManager() {}
	~StageManager() {}

public:
	Stage& GetStage();
	Stage CreateStage(EStageType stageType);
	string GetCurrentStageName() { return currentStage->GetName(); }
	EStageType GetCurrentStageType() { return stageType; }
	void SetCurrentStageType(EStageType stageType ) { this->stageType = stageType; }

private:
	unique_ptr<Stage> currentStage;
	EStageType stageType;
};