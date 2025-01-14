#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class InputVerify
{
public:
	 static int IntegerVerify(int& input, const int& begin, const int& end)
	{
		while (true)
		{
			std::cin >> input;

			if (std::cin.fail() || input < begin || input > end)
			{
				std::cout << u8"잘못된 입력입니다. ";
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				return input;
			}
		}
	}

	static std::string StringVerify()
	{
		std::string input;

		while (true)
		{
			std::cin.ignore();
			std::getline(std::cin, input);
			// 공백만 입력되었는지 확인
            if (!input.empty() && !std::all_of(input.begin(), input.end(),
				[](const unsigned char& ch) { return std::isspace(static_cast<unsigned char>(ch)); }))
			{	
				return input;
			}
			else
			{
				std::cin.clear();
				std::cout << u8"잘못된 입력입니다. 다시 입력해주세요: ";
			}
		}
	}

	static char CharVerify(char* index, const int& length)
	{
		char input = 0;
		bool findFlag = false;

		while (true)
		{
			std::cin >> input;

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
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				return input;
			}
			else if (std::cin.fail() || !findFlag)
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				cout << u8"다시 입력하세요. ";
			}
		}
	}
};