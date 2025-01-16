#include "scene_manager.h"
#include "../03_ingame/Scenes/01_start_scene.h"
#include "../03_ingame/Scenes/02_loading_scene.h"
#include "../03_ingame/Scenes/03_player_setting_scene.h"
#include "../03_ingame/Scenes/04_town_scene.h"
#include "../03_ingame/Scenes/05_shop_scene.h"
#include "../03_ingame/Scenes/06_job_center_scene.h"
#include "../03_ingame/Scenes/07_select_stage_scene.h"
#include "../03_ingame/Scenes/08_dungeon_scene.h"
#include "../03_ingame/Scenes/09_boss_scene.h"
#include "../03_ingame/Scenes/10_end_scene.h"
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
		case None:
			break;
		case EST_START:
			newScene = new StartScene();
			break;
		case EST_LOADING:
			newScene = new LoadingScene();
			break;
		case EST_PLAYER_SETTING:
			newScene = new PlayerSettingScene();
			break;
		case EST_TOWN:
			newScene = new TownScene();
			break;
		case EST_SHOP:
			newScene = new ShopScene();
			break;
		case EST_JOB_CENTER:
			newScene = new JobCenterScene();
			break;
		case EST_SELECT_STAGE:
			newScene = new SelectStageScene();
			break;
		case EST_DUNGEON:
			newScene = new DungeonScene();
			break;
		case EST_BOSS:
			newScene = new BossScene();
			break;
		case EST_END:
			newScene = new EndScene();
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
