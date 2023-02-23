#pragma once

#include "Object.hpp"
#include "../GridSystem/Cell.hpp"

class NormalRabbid : public Object
{
public:
    NormalRabbid(Cell *cellPosition);
    const Cell &GetCellPosition() const override;
    void Print() const override;
};