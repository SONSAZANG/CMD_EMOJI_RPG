#pragma once
#include <string>
#include <vector>
#include "player/player.h"

using namespace std;

class Job
{
private:
	const vector<string> jobs = { "����", "�ü�", "��ؽ�" };

public:
	void ShowJobOptions() const;
	void ChooseJob(Player* player);
};

