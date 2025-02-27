#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

class UTIL 
{
public:
	#define uprint UTIL::UPrint
	static void UPrint(string str)
	{
		cout << u8"" + str;
	}
	#define uprintendl UTIL::UPrintEndl
	static void UPrintEndl(string str)
	{
		cout << u8"" + str << endl;
	}
	#define ustring UTIL::UString
	static string UString(string str)
	{
		return u8"" + str;
	}

	static int IntegerVerify(int& input, const int& begin, const int& end)
	{
		COORD coord = { (SHORT)6, (SHORT)27 };
		
		while (true)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			uprint("  ");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cin >> input;

			if (cin.fail() || input < begin || input > end)
			{
				//UPrint("잘못된 입력입니다. ");
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				return input;
			}
		}
	}

	static string StringVerify()
	{
		string input;
		COORD coord = { (SHORT)6, (SHORT)27 };
		while (true)
		{
			cin.ignore();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			uprint("  ");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			getline(cin, input);
			// 공백만 입력되었는지 확인
			if (!input.empty() && !all_of(input.begin(), input.end(),
				[](const unsigned char& ch) { return isspace(static_cast<unsigned char>(ch)); }))
			{
				return UString(input);
			}
			else
			{
				cin.clear();
				//UPrint("잘못된 입력입니다. 다시 입력해주세요: ");
			}
		}
	}

	static char CharVerify(char* index, const int& length)
	{
		char input = 0;
		bool findFlag = false;
		COORD coord = { (SHORT)6, (SHORT)27 };
		while (true)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			uprint("  ");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cin >> input;

			for (int i = 0; i < length; ++i)
			{
				if (input == index[i])
				{
					findFlag = true;
					break;
				}
			}

			if (findFlag)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				return input;
			}
			else if (cin.fail() || !findFlag)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				//uprint("다시 입력하세요. ");
			}
		}
	}
};