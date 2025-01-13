#include "loading_scene.h"
#include "../../04_Util/gui.h"
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
	// 배경 박스
	GUI::DrawBox();

	// 로딩씬 타이틀
	GUI::PrintLoadingText();

	// 메뉴 박스
	GUI::DrawBox(20, 20, 80, 3);

	GUI::GoToXY(22, 21);
	string loadingText[] = {"\xF0\x9F\x92\x99", "\xF0\x9F\x92\x9A", "\xF0\x9F\x92\x9B" , "\xF0\x9F\x92\x9C"};
	for (int i = 0; i < 38; i++) 
	{
		Sleep(80);
		cout << loadingText[i % 4];
	}

	// SceneManager::GetInstance()->LoadScene(EST_TOWN);
	GameManager::GetInstance()->Run();
}
