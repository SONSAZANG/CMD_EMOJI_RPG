#include "Job.h"
#include "../04_Util/util.h"

void Job::ShowJobOptions() const
{
	uprintendl("전직 가능한 직업 목록: ");

	for (int i = 0; i < jobs.size(); i++)
	{
		cout << i + 1 << ". " << jobs[i] << "\n";
	}
}

string Job::ChooseJob(Player* player)
{
	ShowJobOptions();

	int choice;

	while (true)
	{
		cout << ustring("전직할 직업을 선택하세요(1-") << jobs.size() << "): ";
		int input = UTIL::IntegerVerify(choice, 1, jobs.size());
		return jobs[input - 1];
	}
}

string Job::GetJobTitle(string job, int level) const
{
	if (level < 5 || level > 10)
	{
		return "";
	}

	for (int i = 0; i < jobs.size(); i++)
	{
		if (job == jobs[i])
		{
			return jobTitles[i][level - 5];
		}
	}
	return "";
}


