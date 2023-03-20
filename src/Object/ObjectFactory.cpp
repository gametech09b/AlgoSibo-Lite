#include "ObjectFactory.hpp"

ObjectFactory::ObjectFactory()
{
}

Object *ObjectFactory::CreateObject(std::string type, Position *position, Direction direction)
{
    if (type == "NormalRabbid")
    {
        return new NormalRabbid(position, direction);
    }
    else
    {
        return nullptr;
    }
}