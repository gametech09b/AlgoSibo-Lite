#pragma once

#include "Object.hpp"
#include "./ControllableObject/NormalRabbid/NormalRabbid.hpp"
#include <string>

class ObjectFactory
{
public:
    /// @brief Construct a new Object Factory object
    ObjectFactory();

    /// @brief Destroy the Object Factory object
    ~ObjectFactory();

    /// @brief Create a new Object
    /// @return Object*
    Object *CreateObject(std::string type, Position *position, Direction direction);

    /// @brief Destroy an Object
    /// @param object
    void DestroyObject(Object *object);
};