#pragma once

#include "../GridSystem/Cell.hpp"

class Object
{
public:
    virtual ~Object() = default;

    virtual const Cell &GetCellPosition() const = 0;
    virtual void Print() const = 0;

protected:
    Cell *_cellPosition;
};