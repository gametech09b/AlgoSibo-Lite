#pragma once

#include "Cell.hpp"

class UnwalkableCell : public Cell
{
public:
    UnwalkableCell(int x, int y);
    const Position &GetPosition() override;
    void Print() override;
};