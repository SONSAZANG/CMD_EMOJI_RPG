#pragma once
#include <iostream>
#include <string>
#include <algorithm>

static class InputVerify
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

	static void StringVerify(std::string& input)
	{
		while (true)
		{
			std::cin.ignore(INT_MAX, '\n');
			std::getline(std::cin, input);

			// 공백만 입력되었는지 확인
			if (!input.empty() && !std::all_of(input.begin(), input.end(), [](char ch) { return std::isspace(ch); }))
			{
				break;
			}
			else
			{
				std::cin.clear();
				std::cout << u8"잘못된 입력입니다. 다시 입력해주세요: ";
			}
		}
	}
};