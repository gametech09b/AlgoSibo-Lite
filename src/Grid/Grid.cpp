#include "Grid.hpp"

Grid::Grid(int width, int height)
{
    _width = width;
    _height = height;

    _grid.resize(_width);
    for (int i = 0; i < _width; i++)
    {
        _grid[i].resize(_height);
    }

    for (int i = 0; i < _width; i++)
    {
        for (int j = 0; j < _height; j++)
        {
            Position *position = new Position{i, j};
            _grid[i][j] = new Cell(*position, true);
        }
    }
}

void Grid::Print()
{
}

Cell *Grid::GetCell(Position *position)
{
    return _grid[position->x][position->y];
}

int Grid::GetWidth()
{
    return _width;
}

int Grid::GetHeight()
{
    return _height;
}