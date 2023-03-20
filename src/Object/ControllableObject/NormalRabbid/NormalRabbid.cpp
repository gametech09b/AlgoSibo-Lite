#include "NormalRabbid.hpp"
#include <iostream>

NormalRabbid::NormalRabbid(Position *position, Direction direction)
{
    _position = position;
    _direction = direction;
}

void NormalRabbid::Print()
{
    std::cout << "N";
}

void NormalRabbid::MoveForward()
{
    switch (_direction)
    {
    case Direction::UP:
        _position->y--;
        break;
    case Direction::DOWN:
        _position->y++;
        break;
    case Direction::LEFT:
        _position->x--;
        break;
    case Direction::RIGHT:
        _position->x++;
        break;
    }
}

void NormalRabbid::MoveBackward()
{
    switch (_direction)
    {
    case Direction::UP:
        _position->y++;
        break;
    case Direction::DOWN:
        _position->y--;
        break;
    case Direction::LEFT:
        _position->x++;
        break;
    case Direction::RIGHT:
        _position->x--;
        break;
    }
}

void NormalRabbid::TurnLeft()
{
    switch (_direction)
    {
    case Direction::UP:
        _direction = Direction::LEFT;
        break;
    case Direction::DOWN:
        _direction = Direction::RIGHT;
        break;
    case Direction::LEFT:
        _direction = Direction::DOWN;
        break;
    case Direction::RIGHT:
        _direction = Direction::UP;
        break;
    }
}

void NormalRabbid::TurnRight()
{
    switch (_direction)
    {
    case Direction::UP:
        _direction = Direction::RIGHT;
        break;
    case Direction::DOWN:
        _direction = Direction::LEFT;
        break;
    case Direction::LEFT:
        _direction = Direction::UP;
        break;
    case Direction::RIGHT:
        _direction = Direction::DOWN;
        break;
    }
}

void NormalRabbid::Interact()
{
}
