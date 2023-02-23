#pragma once

#include "Cell.hpp"
#include "../ControllableObject/Object.hpp"

class StartCell : public Cell
{
public:
    StartCell(int x, int y);
    const Position &GetPosition() override;
    void Print() override;

    void SpawnObject(Object *object);

private:
    Object *_object;
};