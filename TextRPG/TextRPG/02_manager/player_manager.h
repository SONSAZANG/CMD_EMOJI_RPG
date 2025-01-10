#pragma once

#include "../01_core/singleton_base.h"
#include "../03_ingame/player/player.h"
#include <iostream>
#include <string>

class PlayerManager : public SingletonBase<PlayerManager>
{
	friend class SingletonBase<PlayerManager>;

private:
	PlayerManager() {};
	~PlayerManager() {};

public:
	void CreatePlayer(const string& name);
	Player& GetPlayer();

private:
	Player player;

};