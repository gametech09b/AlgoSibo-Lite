#include <iostream>
#include "./Level/Level.hpp"
#include "./UI/DisplayManager.hpp"

int main()
{
    Level *level1 = new Level("../levels/1.txt", "Level 1");

    DisplayManager::PrintLevel(level1);

    level1->SetCurrentControllableObject(0);

    NormalRabbid *normalRabbid = static_cast<NormalRabbid *>(level1->GetCurrentControllableObject());

    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);

    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);
    
    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);

    normalRabbid->TurnRight();
    DisplayManager::PrintLevel(level1);

    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);

    normalRabbid->TurnLeft();
    DisplayManager::PrintLevel(level1);

    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);
    
    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);

    normalRabbid->TurnLeft();
    DisplayManager::PrintLevel(level1);

    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);

    normalRabbid->TurnRight();
    DisplayManager::PrintLevel(level1);

    normalRabbid->MoveForward();
    DisplayManager::PrintLevel(level1);

    return 0;
}