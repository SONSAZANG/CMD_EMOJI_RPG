#pragma once
#include "../01_core/singleton_base.h"
#include "../01_core/scene_base.h"
class SceneManager : public SingletonBase<SceneManager>
{
	friend class SingletonBase<SceneManager>;

private:
	SceneManager() {};
	~SceneManager() {};

public:
	void Init();

public:
	void LoadScene(ESceneType sceneType);
	ESceneType GetSceneType() { return sceneType; }
	void SetStageProgress(int stage) { stageProgress = stage; }
	int GetStageProgress() { return stageProgress; }

private:
	class SceneBase* scene;
	ESceneType sceneType;
	int stageProgress;
};