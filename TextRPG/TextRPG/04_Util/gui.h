#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "../04_Util/util.h"
using namespace std;
class GUI
{
public:
	static void GoToXY(const int x, const int y)
	{
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	
	/// <summary>
	/// 아무것도 입력 안하면 기본 배경 박스(0, 0, 120, 30)
	/// </summary>
	static void DrawFullBox() 
	{
		DrawBox(0, 0, 120, 30);
	}

	static void DrawInGameBox() 
	{
		DrawBox(0, 0, 120, 20);
		DrawBox(0, 20, 120, 10);
	}

	static void DrawBox(const int x, const int y, const int width, const int height)
	{
		for (int i = 0; i < height; i++)
		{
			GoToXY(x, y + i);
			if (i == 0 || i == height - 1) {
				cout << "+" << string(width - 2, '-') << "+";
			}
			else {
				cout << "|" << string(width - 2, ' ') << "|";
			}
		}
	}

	static void DrawTextBox(const int x, const int y, const int width, const int height, string inputText = ustring("준비중입니다."))
	{
		DrawBox(x, y, width, height);
		GoToXY(x + 2, y + 2);
		uprint(inputText);
	}

	static void PrintTitleText() 
	{
		string text[] = {
			" _____ __  __  ___      _ ___           ____  ____   ____ ",
			"| ____|  \\/  |/ _ \\    | |_ _|         |  _ \\|  _ \\ / ___|",
			"|  _| | |\\/| | | | |_  | || |   _____  | |_) | |_) | |  _ ",
			"| |___| |  | | |_| | |_| || |  |_____| |  _ <|  __/| |_| |",
			"|_____|_|  |_|\\___/ \\___/|___|         |_| \\_\\_|    \\____|",
		};
		GoToXY(31, 4);
		for (int i = 0; i < 8; i++) 
		{
			UTIL::UPrint("✨ ♦ ♦ ");
		}
		UTIL::UPrint("✨");
		GoToXY(31, 5);
		cout << text[0] << endl;
		GoToXY(31, 6);
		cout << text[1] << endl;
		GoToXY(31, 7);
		cout << text[2] << endl;
		GoToXY(31, 8);
		cout << text[3] << endl;
		GoToXY(31, 9);
		cout << text[4] << endl;
		GoToXY(31, 10);
		for (int i = 0; i < 8; i++)
		{
			UTIL::UPrint("✨ ♦ ♦ ");
		}
		UTIL::UPrint("✨");
	}
	
	static void PrintLoadingText()
	{
		string text[] = {
			" _     ___    _    ____ ___ _   _  ____   _   _ ",
			"| |   / _ \\  / \\  |  _ \\_ _| \\ | |/ ___| | | | |",
			"| |  | | | |/ _ \\ | | | | ||  \\| | |  _  | | | |",
			"| |__| |_| / ___ \\| |_| | || |\\  | |_| | |_| |_|",
			"|_____\\___/_/   \\_\\____/___|_| \\_|\\____| (_) (_)",
		};
		GoToXY(36, 5);
		cout << text[0] << endl;
		GoToXY(36, 6);
		cout << text[1] << endl;
		GoToXY(36, 7);
		cout << text[2] << endl;
		GoToXY(36, 8);
		cout << text[3] << endl;
		GoToXY(36, 9);
		cout << text[4];
	}

	static void SettingTitle(string title) 
	{
		GoToXY(4, 2);
		uprintendl(title);
	}

	// 플레이어와 몬스터를 출력하기 위한 박스
	static void DrawNamingBox(vector<string> boxNames)
	{
		switch (boxNames.size())
		{
			case 1:
				DrawTextBox(46, 5, 28, 5, boxNames[0]);
				break;
			case 2:
				DrawTextBox(28, 5, 28, 5, boxNames[0]);
				DrawTextBox(72, 5, 28, 5, boxNames[1]);
				break;
			default:
				break;
		}
	}

	// 선택 목록을 출력하는 박스(전직소, 상점 등)
	static void DrawSelectBox(vector<string> boxNames) 
	{
		switch (boxNames.size())
		{
			case 1:
				DrawTextBox(50, 12, 20, 5, boxNames[0]);
				break;
			case 2:
				DrawTextBox(26, 12, 20, 5, boxNames[0]);
				DrawTextBox(74, 12, 20, 5, boxNames[1]);
				break;
			case 3:
				DrawTextBox(14, 12, 20, 5, boxNames[0]);
				DrawTextBox(50, 12, 20, 5, boxNames[1]);
				DrawTextBox(86, 12, 20, 5, boxNames[2]);
				break;
			default:
				break;
		}
	}

	static void DrawQuestionText(vector<string> questionTexts)
	{
		GoToXY(4, 22);
		uprint(questionTexts[0]);
		GoToXY(4, 23);
		uprint(questionTexts[1]);
		GoToXY(4, 24);
		uprint(questionTexts[2]);

		GoToXY(4, 27);
		uprint("->");
	}

	static void DrawStoryBox(vector<string> storyTexts)
	{
		GoToXY(30, 4);
		uprint(storyTexts[0]);
		Sleep(1000);
		GoToXY(30, 9);
		uprint(storyTexts[1]);
		Sleep(1000);
		GoToXY(30, 14);
		uprint(storyTexts[2]);
	}
};