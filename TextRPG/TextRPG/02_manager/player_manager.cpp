#include "player_manager.h"
#include "../03_ingame/player/player.h"
#include <iostream>
#include <string>

using namespace std;

void PlayerManager::CreatePlayer(const string& name)
{
	player.SetName(name);
}

Player& PlayerManager::GetPlayer()
{
	return player;
}
