#pragma once
#include <string>
#include <vector>

#include "player/player.h"

using namespace std;

class Job
{
private:
	const vector<string> jobs = { u8"전사", u8"궁수", u8"어쌔신" };
	const vector<vector<string>> jobTitles = {
		{ u8"Lv1.전사", u8"Lv2.전사", u8"Lv3.전사", u8"Lv4.전사", u8"Lv5.전사", u8"만렙 전사" },
		{ u8"Lv1.궁수", u8"Lv2.궁수", u8"Lv3..궁수", u8"Lv4.궁수", u8"Lv5.궁수", u8"만렙 궁수" },
		{ u8"Lv1.어쌔신", u8"Lv2.어쌔신", u8"Lv3.어쌔신", u8"Lv4.어쌔신", u8"Lv5.어쌔신", u8"만렙 어쌔신" }
	};

public:
	void ShowJobOptions() const;
	void ChooseJob(Player* player);

	string GetJobTitle(string job, int level) const;
};

