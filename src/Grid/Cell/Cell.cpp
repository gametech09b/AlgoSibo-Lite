#include "Cell.hpp"

Cell::Cell(Position *position, bool isWalkable)
{
    _position = position;
    _isWalkable = isWalkable;
}

Position &Cell::GetPosition()
{
    return *_position;
}

void Cell::SetPosition(Position &position)
{
    _position = &position;
}

bool &Cell::GetIsWalkable()
{
    return _isWalkable;
}

void Cell::SetIsWalkable(bool &isWalkable)
{
    _isWalkable = isWalkable;
}