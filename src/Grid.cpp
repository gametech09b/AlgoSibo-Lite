#include "./headers/GridSystem/Grid.hpp"
#include <iostream>

Grid::Grid(int width, int height)
{
    _width = width;
    _height = height;
    
    _gridCells.resize(_width);
    for (int i = 0; i < _width; i++)
    {
        _gridCells[i].resize(_height);
    }
}

void Grid::Print()
{
    for (int i = 0; i < _width; i++)
    {
        for (int j = 0; j < _height; j++)
        {
            _gridCells[i][j]->Print();
        }
        std::cout << std::endl;
    }
}

