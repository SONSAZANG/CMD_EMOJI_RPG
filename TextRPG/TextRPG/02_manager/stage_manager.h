#pragma once
#include "../01_core/singleton_base.h"
#include "../03_ingame/stage.h"
class StageManager : public SingletonBase<StageManager> {

	friend class SingletonBase<StageManager>;

private:
	StageManager() : currentStage(nullptr) {}
	~StageManager() {}

public:
	Stage& GetStage();
	unique_ptr<Stage> CreateStage(EStageType stageType);
	string GetCurrentStageName() { return currentStage->GetName(); }
	EStageType GetCurrentStageType() { return stageType; }
	void SetCurrentStageType(EStageType stageType) { this->stageType = stageType; }
	void SetClearStageNum(int num) { if (clearStageNum < num) clearStageNum = num; }
	int GetClearStageNum() { return clearStageNum; }

private:
	unique_ptr<Stage> currentStage;
	EStageType stageType;
	int clearStageNum = 0;

};