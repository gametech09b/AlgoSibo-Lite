#include "ObjectFactory.hpp"

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

void ObjectFactory::DestroyObject(Object *object)
{
    delete object;
}