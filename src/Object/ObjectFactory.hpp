#pragma once

#include "Object.hpp"
#include "./ControllableObject/NormalRabbid/NormalRabbid.hpp"
#include <string>

/// @brief Object Factory class
class ObjectFactory
{
public:
    /// @brief Create a new Object
    /// @return Object*
    static Object *CreateObject(std::string type, Position *position, Direction direction);

    /// @brief Destroy an Object
    /// @param *object
    static void DestroyObject(Object *object);
};