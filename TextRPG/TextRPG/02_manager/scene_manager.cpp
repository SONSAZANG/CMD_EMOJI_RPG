#include "scene_manager.h"
#include "../03_ingame/Scenes/start_scene.h"
#include "../03_ingame/Scenes/loading_scene.h"
#include "../03_ingame/Scenes/town_scene.h"
#include "../03_ingame/Scenes/select_stage_scene.h"
#include "../03_ingame/Scenes/dungeon_scene.h"
#include <windows.h>

void SceneManager::Init()
{
	if(scene) scene->Init();
}

void SceneManager::LoadScene(ESceneType sceneType)
{
	// 현재 씬과 동일한지 확인
	if(this->sceneType == sceneType) return;

	SceneBase* newScene = nullptr;

	switch (sceneType)
	{
		case EST_START:
			newScene = new StartScene();
			break;
		case EST_LOADING:
			newScene = new LoadingScene();
			break;
		case EST_TOWN:
			newScene = new TownScene();
			break;
		case EST_SELECT_STAGE:
			newScene = new SelectStageScene();
		case EST_DUNGEON:
			newScene = new DungeonScene();
			break;
		default:
			break;
	}
	
	if (scene) 
	{
		delete scene;
		scene = nullptr;
	}

	scene = newScene;
	this->sceneType = sceneType;

	system("cls");

	newScene->Init();
}
