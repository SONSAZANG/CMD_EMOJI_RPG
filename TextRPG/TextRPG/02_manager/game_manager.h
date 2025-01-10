#pragma once

#include "../01_core/singleton_base.h"
#include <iostream>
using namespace std;
class GameManager : public SingletonBase<GameManager>
{
public:
	void Loading();
	void Run();
	void CreatePlayer();
	void Battle();
	void VisitShop();
	void Exit();

private:
	bool IsPlaying;
};