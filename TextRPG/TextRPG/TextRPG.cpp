#include <iostream>
#include "02_manager/game_manager.h"

int main()
{
    GameManager* gameManager = GameManager::GetInstance();
    
    gameManager->Init();
    //gameManager->Test();

    return 0;
}