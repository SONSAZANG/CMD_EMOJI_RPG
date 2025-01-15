#include "01_start_scene.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "../../02_manager/scene_manager.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
using namespace std;

void StartScene::Init()
{
	DrawMainLayout();
	SelectCommand();
}		



void StartScene::DrawMainLayout()
{
	// 배경 박스
	GUI::DrawFullBox();

	// 타이틀 박스
	SetConsoleOutputCP(CP_UTF8);
	GUI::PrintTitleText();

	// 메뉴 박스
	GUI::DrawBox(30, 16, 60, 9);
	GUI::GoToXY(35, 18);
	UTIL::UPrint("📌 1. 게임 시작");
	GUI::GoToXY(35, 20);
	UTIL::UPrint("📌 2. 게임 종료");
}

void StartScene::SelectCommand() {
	char choice;
	while (true) {
		if (SceneManager::GetInstance()->GetSceneType() != EST_START) break;

		GUI::GoToXY(35, 22);
		UTIL::UPrint("선택한 번호 입력: ");
		cin >> choice;

		switch (choice) {
		case '1':
			SceneManager::GetInstance()->LoadScene(EST_LOADING);
			break;
		case '2':
			// cmd 클리어 명령어
			system("cls");
			cout << "Exiting Game..." << endl;
			exit(0);
			break;
		default:
			cout << "Invalid option. Try again." << endl;
		}
	}
}