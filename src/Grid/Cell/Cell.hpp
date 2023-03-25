#pragma once

#include "../../Core/Position.hpp"

class Cell
{
public:
    Cell(Position *position, bool isWalkable);

    Position &GetPosition();

    void SetPosition(Position &position);

    bool &GetIsWalkable();

    void SetIsWalkable(bool &isWalkable);

private:
    Position *_position;
    bool _isWalkable;
};