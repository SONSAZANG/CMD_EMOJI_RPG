#include "Job.h"

void Job::ShowJobOptions() const
{
	cout << "���� ������ ���� ���:\n";

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
		cout << "������ ������ �����ϼ���(1-" << jobs.size() << "): ";
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
				cout << "�߸��� �Է��Դϴ�. 1-" << jobs.size() << " ������ ���ڸ� �Է����ּ���.\n";
			}
		}
		catch (invalid_argument& e)
		{
			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���.\n";
		}
		catch (out_of_range& e)
		{
			cout << "�Է��� ���ڰ� �ʹ� Ů�ϴ�. 1-" << jobs.size() << "������ ���ڸ� �Է����ּ���.\n";
		}
	}
	cout << "�����մϴ�! '" << player->GetJob() << "'�� �����߽��ϴ�!" << endl;
}
