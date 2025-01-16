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
	//const vector<vector<string>> jobTitles = {
	//	{ ustring("Lv1.전사"), ustring("Lv2.전사"), ustring("Lv3.전사"), ustring("Lv4.전사"), ustring("Lv5.전사"), ustring("피로 물든 검귀") },
	//	{ ustring("Lv1.궁수"), ustring("Lv2.궁수"), ustring("Lv3..궁수"), ustring("Lv4.궁수"), ustring("Lv5.궁수"), ustring("명사수") },
	//	{ ustring("Lv1.도적"), ustring("Lv2.도적"), ustring("Lv3.도적"), ustring("Lv4.도적"), ustring("Lv5.도적"), ustring("냉혹한 암살자") }
	//};

public:
	void ShowJobOptions() const;
	string ChooseJob(Player* player);

	//string GetJobTitle(string job, int level) const;
};