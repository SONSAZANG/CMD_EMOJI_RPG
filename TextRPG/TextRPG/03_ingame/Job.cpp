#include "Job.h"

void Job::ShowJobOptions() const
{
	cout << "전직 가능한 직업 목록:\n";

	for (int i = 0; i < jobs.size(); i++)
	{
		cout << i + 1 << ". " << jobs[i] << "\n";
	}
}

void Job::ChooseJob(Player* player)
{
	ShowJobOptions();

	string input;
	int choice;

	while (true)
	{
		cout << "전직할 직업을 선택하세요(1-" << jobs.size() << "): ";
		getline(cin, input);

		try
		{
			choice = stoi(input);

			if (choice >= 1 && choice <= static_cast<int>(jobs.size()))
			{
				player->SetJob(jobs[choice - 1]);
				break;
			}
			else
			{
				cout << "잘못된 입력입니다. 1-" << jobs.size() << " 사이의 숫자를 입력해주세요.\n";
			}
		}
		catch (invalid_argument& e)
		{
			cout << "잘못된 입력입니다. 숫자를 입력해주세요.\n";
		}
		catch (out_of_range& e)
		{
			cout << "입력한 숫자가 너무 큽니다. 1-" << jobs.size() << "사이의 숫자를 입력해주세요.\n";
		}
	}
	cout << "축하합니다! '" << player->GetJob() << "'로 전직했습니다!" << endl;
}
