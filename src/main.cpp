#include <iostream>
// #include "./GameManager/GameManager.hpp"
#include "./Level/Level.hpp"

int main()
{
    Level *level = new Level("Hehe");

    level->Print();

    return 0;
}