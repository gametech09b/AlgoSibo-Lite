#pragma once

#include "Cell.hpp"

class WalkableCell : public Cell
{
public:
    WalkableCell(int x, int y);
    const Position &GetPosition() override;
    void Print() override;

    void SetOccupied(bool isOccupied);
    bool GetIsOccupied();

private:
    bool _isOccupied;
};