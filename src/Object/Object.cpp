#include "Object.hpp"

Direction &Object::GetDirection()
{
    return _direction;
}

void Object::SetDirection(Direction &direction)
{
    _direction = direction;
}

Position Object::GetPosition()
{
    return *_position;
}

void Object::SetPosition(Position &position)
{
    _position = &position;
}
