#include "02_loading_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/scene_manager.h"
#include "../../02_manager/game_manager.h"
#include <iostream>
#include <windows.h>
using namespace std;

void LoadingScene::Init()
{
	DrawMainLayout();
}

void LoadingScene::DrawMainLayout()
{
	SetConsoleOutputCP(CP_UTF8);
	
	// 배경 박스
	GUI::DrawFullBox();

	// 로딩씬 타이틀
	GUI::PrintLoadingText();

	// 메뉴 박스
	GUI::DrawBox(20, 20, 80, 3);

	GUI::GoToXY(22, 21);
	for (int i = 0; i < 19; i++) 
	{
		Sleep(100);
		UTIL::UPrint("🟨");
		UTIL::UPrint("🟧");
	}

	SceneManager::GetInstance()->LoadScene(EST_PLAYER_SETTING);
	// GameManager::GetInstance()->Run();
}
