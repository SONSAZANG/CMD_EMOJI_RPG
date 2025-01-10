#include "player_manager.h"
#include "../03_ingame/player/player.h"
#include <iostream>
using namespace std;
Player PlayerManager::CreatePlayer()
{
	Player player;
	player.SetInfo(200);
	return player;
}
