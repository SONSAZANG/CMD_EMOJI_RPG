#pragma once
#include <string>
#include <vector>

#include "../01_core/singleton_base.h"
#include "../04_Util/util.h"
#include "../03_ingame/player/player.h"

using namespace std;

class JobManager : public SingletonBase<JobManager>
{
	friend class SingletonBase<JobManager>;

private:
	JobManager() {};
	~JobManager() {};

	const vector<string> jobs = { ustring("⚔️"), ustring("🏹"), ustring("🗡️") };

public:
	void ShowJobOptions() const;
	string ChooseJob(Player* player);
};