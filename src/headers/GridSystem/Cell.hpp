#pragma once

struct Position
{
    int x;
    int y;
};

class Cell
{
public:
    virtual ~Cell() = default;
    
    virtual const Position &GetPosition() = 0;
    virtual void Print() = 0;

protected:
    Position _position;
};