#include "./headers/GridSystem/WalkableCell.hpp"
#include <iostream>

WalkableCell::WalkableCell(int x, int y)
{
    _position.x = x;
    _position.y = y;
}

const Position &WalkableCell::GetPosition()
{
    return _position;
}

void WalkableCell::Print()
{
    std::cout << "W";
}

void WalkableCell::SetOccupied(bool isOccupied)
{
    _isOccupied = isOccupied;
}

bool WalkableCell::GetIsOccupied()
{
    return _isOccupied;
}