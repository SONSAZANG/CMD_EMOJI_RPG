#include <iostream>
#include "02_manager/player_manager.h"
#include "02_manager/game_manager.h"
int main()
{
    GameManager* gameManager = GameManager::GetInstance();
    gameManager->Loading();

    return 0;
}