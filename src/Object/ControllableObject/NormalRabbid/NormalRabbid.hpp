#pragma once

#include "../IControllable.hpp"
#include "../../Object.hpp"
#include "../../../Core/Direction.hpp"
#include "../../../Core/Position.hpp"

class NormalRabbid : public Object, public IControllable
{
public:
    NormalRabbid(Position *position, Direction direction);
    void Print() override;

    void MoveForward() override;
    void MoveBackward() override;
    void TurnLeft() override;
    void TurnRight() override;
    void Interact() override;
};