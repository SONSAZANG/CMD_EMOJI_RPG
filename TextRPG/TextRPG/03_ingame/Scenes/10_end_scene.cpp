#include "10_end_scene.h"
#include "Windows.h"
#include <conio.h>
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/stage_manager.h"
#include "../../02_manager/game_manager.h"
void EndScene::Init()
{
	DrawMainLayout();
}

void EndScene::DrawMainLayout()
{
	GUI::DrawFullBox();

	// 보스 몬스터 클리어 여부 확인
	if (StageManager::GetInstance()->GetClearStageNum() >= 4)
	{
		DrawBossClearLayout();
		DrawBrokenLayout();
		DrawClearLayout();
	}
	else
	{
		DrawFailLayout();
	}
}

void EndScene::DrawBossClearLayout()
{
	GUI::GoToXY(35, 12);
	uprint("드디어...!");
	Sleep(1000);

	GUI::GoToXY(35, 15);
	uprint("이제 현실로 돌아갈 수 있는건가?!");
	Sleep(1000);

	GUI::GoToXY(35, 18);
	uprint("엇..갑자기 어지러운데...");
	Sleep(1000);

	GUI::GoToXY(35, 19);
	uprint("(진행하려면 아무키나 입력하세요.)");

	_getch();
}

void EndScene::DrawBrokenLayout()
{
	system("cls");
	cout << "                                       █                                                               " << endl;
	cout << "                                        █                                                              " << endl;
	cout << "                                          █                █                                           " << endl;
	cout << "                                           █               ██                                  █       " << endl;
	cout << "                                            █               ██                               █         " << endl;
	cout << "                                              █   █         ██   █                        █            " << endl;
	cout << "                          ▓████                █████       ██                        ▓███              " << endl;
	cout << "                                   ███           ███▓▓     █                        ██                 " << endl;
	cout << "                                         █▓       █▓▓███   █   █                ▓███                   " << endl;
	cout << "                                           ███     █▓█ ██  █  ▓               ▓███                     " << endl;
	cout << "                                               ██   ██  ▓▓ ██ ▓█   ▓▓▓▓▓▓█▓███                         " << endl;
	cout << "                                                  █▓  ██████████ ▓█   ███                              " << endl;
	cout << "                                         ████       ▓▓█ ████▓▓ ██  ▓█                                  " << endl;
	cout << "                                               ▓███ ▓ ██▓▓▓▓▓▓▓█████ ███                               " << endl;
	cout << "                                                ██▓███▓▓▓▓▓▓▓▓▓▓▓████                                  " << endl;
	cout << "                                            ███▓▓████▓▓▓▓▓▓▓▓▓▓▓▓███                                   " << endl;
	cout << "                                              ▓▓████▓▓▓▓▓▓▓▓▓▓▓▓ █████████▓▓                           " << endl;
	cout << "                                         █████   ▓▓██▓▓▓█▓▒ ▓▓ ▓▓█▓██     ██ ██                        " << endl;
	cout << "                                         █   ▓▓█     ████▓▓▓▓██ ███████         ███                    " << endl;
	cout << "                                        ██████      ████▓▓▓██ ███▓    ███           ██                 " << endl;
	cout << "                                    ▓████      █     █  ▓▓▓▓██ █▓  ██     ██                           " << endl;
	cout << "                                ▓███           ██  ▓   ▓█ ▓ ██ ██   █        █                         " << endl;
	cout << "                            ▓██                  ▓▓   ▓ ▓▓█    ▓█                                      " << endl;
	cout << "                         ██                     ▓▓   ▓  ▓▓  ██  █     █                                " << endl;
	cout << "                     ██                        ▓    ███▓▓█  ██  █      █                               " << endl;
	cout << "                                                   █    █    █  █       █                              " << endl;
	cout << "                                                   █    █        █       █                             " << endl;
	cout << "                                                  █     █                 █                            " << endl;
	cout << "                                                                            █                          ";
	Sleep(3000);
}

void EndScene::DrawClearLayout()
{
	GUI::DrawFullBox();
	GUI::PrintClearText();

	GUI::GoToXY(30, 18);
	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	cout << playerName << ustring("당신은 cmd로부터 탈출에 성공했습니다!");
	Sleep(500);

	GUI::GoToXY(30, 20);
	uprint("게임을 클리어 했습니다! 플레이 해주셔서 감사합니다.");
	Sleep(500);

	GUI::GoToXY(30, 22);
	uprint("제작자 : 손은수 이학민 김민수 한가윤 장종기");
	GUI::GoToXY(30, 23);
	uprint("스파르타 코딩클럽 내일 배움 캠프 언리얼 1기 17조");

	_getch();
}

void EndScene::DrawFailLayout()
{
	GUI::PrintFailText();

	GUI::GoToXY(30, 18);
	uprint("플레이어가 죽었습니다.");
	Sleep(1000);
	GUI::GoToXY(30, 21);
	uprint("다시 시작하시겠습니까?");
	Sleep(1000);
	GUI::GoToXY(30, 24);
	uprint("(진행하려면 아무키나 입력하세요.)");

	_getch();

	GameManager::GetInstance()->Clear();
}
