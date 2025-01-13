#include "start_scene.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "../../02_manager/scene_manager.h"
#include "../../04_Util/gui.h"
using namespace std;

void StartScene::Init()
{
	DrawMainLayout();
	// 입력 받기
	HandleStartInput();
}		



void StartScene::DrawMainLayout()
{
	// 배경 박스
	GUI::DrawBox();

	// 타이틀 박스
	SetConsoleOutputCP(CP_UTF8);
	GUI::PrintTitleText();

	// 메뉴 박스
	GUI::DrawBox(30, 16, 60, 9);
	GUI::GoToXY(35, 18);
	cout << "1. Start Game" << "\xF0\x9F\x98\x8E";
	GUI::GoToXY(35, 20);
	cout << "2. Exit Game" << "\xF0\x9F\x98\xB4";
}

void StartScene::HandleStartInput() {
	char choice;
	while (true) {
		if (SceneManager::GetInstance()->GetSceneType() != EST_START) break;

		GUI::GoToXY(35, 22);
		cout << "Choose an option: ";
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