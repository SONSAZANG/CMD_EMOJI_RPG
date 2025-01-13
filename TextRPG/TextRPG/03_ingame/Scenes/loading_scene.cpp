#include "loading_scene.h"
#include "../../04_Util/gui.h"
#include <iostream>
using namespace std;

void LoadingScene::Init()
{
	cout << "LoadingScene Init() !!" << endl;
}

void LoadingScene::Clear()
{
}

void LoadingScene::DrawMainLayout()
{
	// 배경 박스
	GUI::DrawBox();


}
