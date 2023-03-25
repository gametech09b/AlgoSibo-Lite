#include <iostream>
#include "./Level/Level.hpp"
#include "./UI/DisplayManager.hpp"

int main()
{
    Level *level1 = new Level("../levels/1.txt", "Level 1");

    DisplayManager::PrintLevel(level1);

    return 0;
}