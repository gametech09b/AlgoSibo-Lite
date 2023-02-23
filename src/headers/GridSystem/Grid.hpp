#pragma once

#include "Cell.hpp"
#include <vector>

class Grid
{
public:
    Grid(int width, int height);
    
    void Print();
    void SetCell(int x, int y, Cell *cell);
    Cell *GetCell(int x, int y);

private:
    std::vector<std::vector<Cell *>> _gridCells;
    int _width;
    int _height;
};