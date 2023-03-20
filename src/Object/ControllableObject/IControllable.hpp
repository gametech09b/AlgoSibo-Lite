#pragma once

class IControllable
{
public:
    virtual void MoveForward() = 0;
    virtual void MoveBackward() = 0;
    virtual void TurnLeft() = 0;
    virtual void TurnRight() = 0;
    virtual void Interact() = 0;
};