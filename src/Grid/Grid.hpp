#pragma once

#include "./Cell/Cell.hpp"
#include "../Core/Position.hpp"
#include <vector>

class Grid
{
public:
    Grid(int width, int height);

    void Print();
    Cell *GetCell(Position *position);

    int GetWidth();
    int GetHeight();

private:
    std::vector<std::vector<Cell *>> _grid;
    int _width;
    int _height;
};