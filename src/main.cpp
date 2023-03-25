#include <iostream>
#include "./Level/Level.hpp"

int main()
{
    Level *level1 = new Level("../levels/1.txt", "Level 1");

    level1->Print();

    return 0;
}