#pragma once

#include "./Cell/Cell.hpp"
#include "../Core/Position.hpp"
#include <vector>

class Grid
{
public:
    Grid(std::vector<std::vector<Cell *>> grid);

    Cell *GetCell(Position *position);

    int GetWidth();
    int GetHeight();

private:
    std::vector<std::vector<Cell *>> grid;
    int width;
    int height;
};