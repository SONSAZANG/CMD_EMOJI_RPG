#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

class UTIL 
{
public:
	#define uprint UTIL::UPrint
	static void UPrint(string str) 
	{
		string a = u8"" + str;
		cout << a;
	}
	#define uprintendl UTIL::UPrintEndl
	static void UPrintEndl(string str)
	{
		string a = u8"" + str;
		cout << a << endl;
	}
	#define ustring UTIL::UString
	static string UString(string str)
	{
		string a = u8"" + str;
		return a;
	}

	static int IntegerVerify(int& input, const int& begin, const int& end)
	{
		while (true)
		{
			cin >> input;

			if (cin.fail() || input < begin || input > end)
			{
				UPrint("잘못된 입력입니다. ");
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

		while (true)
		{
			cin.ignore();
			getline(cin, input);
			string a = UString(input);
			// 공백만 입력되었는지 확인
			if (!input.empty() && !all_of(input.begin(), input.end(),
				[](const unsigned char& ch) { return isspace(static_cast<unsigned char>(ch)); }))
			{
				return a;
			}
			else
			{
				cin.clear();
				UPrint("잘못된 입력입니다. 다시 입력해주세요: ");
			}
		}
	}
};