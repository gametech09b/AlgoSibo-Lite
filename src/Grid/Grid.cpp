#include "Grid.hpp"

Grid::Grid(std::vector<std::vector<Cell *>> grid)
{
    this->grid = grid;
    width = grid.size();
    height = grid[0].size();
}

Cell *Grid::GetCell(Position *position)
{
    return grid[position->x][position->y];
}

int Grid::GetWidth()
{
    return width;
}

int Grid::GetHeight()
{
    return height;
}