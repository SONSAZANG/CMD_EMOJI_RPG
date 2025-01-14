#pragma once
#include <string>
#include <vector>
#include "player/player.h"

using namespace std;

class Job
{
private:
	const vector<string> jobs = { u8"전사", u8"궁수", u8"어쌔신" };

public:
	void ShowJobOptions() const;
	void ChooseJob(Player* player);
};

