#pragma once

#include "../Core/Position.hpp"
#include "../Core/Direction.hpp"

class Object
{
public:
    /// @brief Get the Position object
    /// @return *Position
    Position GetPosition();

    /// @brief Set the Position object
    /// @param position
    void SetPosition(Position &position);

    /// @brief Get the Direction object
    /// @return Direction&
    Direction &GetDirection();

    /// @brief Set the Direction object
    /// @param &direction
    void SetDirection(Direction &direction);

    /// @brief Print the object
    virtual void Print() = 0;

protected:
    Position *_position;
    Direction _direction;
};