#include <iostream>
#include <vector>
#include "Character.h"
#include "Berserker.h"
#include "Hybrid.h"
#include "Mage.h"
#include "GameInput.h"
#include "GameManager.h"
#include <cstdlib>
using namespace std;

int main()
{
    GameManager manager;
    srand(time(NULL));

    //manager.Init();
    //manager.Run();
    manager.Test();
}