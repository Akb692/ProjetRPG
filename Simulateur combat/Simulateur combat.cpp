#include <iostream>
#include <ctime>
#include <cstdlib>
#include "GameManager.h"

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    GameManager manager;
    manager.Init();
    manager.Run();
    manager.ShutDown();
    return 0;
}
