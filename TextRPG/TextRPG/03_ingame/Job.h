#pragma once
#include <string>
#include <vector>
#include "player/player.h"

using namespace std;

class Job
{
private:
	const vector<string> jobs = { "Àü»ç", "±Ã¼ö", "¾î½Ø½Å" };

public:
	void ShowJobOptions() const;
	void ChooseJob(Player* player);
};

