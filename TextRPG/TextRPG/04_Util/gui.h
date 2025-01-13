#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
static class GUI
{
public:
	static void GoToXY(int x, int y)
	{
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	
	/// <summary>
	/// 아무것도 입력 안하면 기본 배경 박스(0, 0, 120, 30)
	/// </summary>
	static void DrawBox() {
		DrawBox(0, 0, 120, 30);
	}

	static void DrawBox(int x, int y, int width, int height)
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

	static void PrintTitleText() {
		string text[] = {
			" _____ __  __  ___      _ ___           ____  ____   ____ ",
			"| ____|  \\/  |/ _ \\    | |_ _|         |  _ \\|  _ \\ / ___|",
			"|  _| | |\\/| | | | |_  | || |   _____  | |_) | |_) | |  _ ",
			"| |___| |  | | |_| | |_| || |  |_____| |  _ <|  __/| |_| |",
			"|_____|_|  |_|\\___/ \\___/|___|         |_| \\_\\_|    \\____|",
		};
		GoToXY(31, 4);
		for (int i = 0; i < 29; i++) cout << "\xF0\x9F\x98\x81";
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
		for (int i = 0; i < 29; i++) cout << "\xF0\x9F\x98\x81";
	}
};