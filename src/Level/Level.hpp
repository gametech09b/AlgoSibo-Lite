#pragma once

#include "../Grid/Grid.hpp"
#include "../Object/Object.hpp"
#include "../Object/ObjectFactory.hpp"
#include <iostream>
#include <string>
#include <vector>

#define RED "\x1b[47;41m"
#define GREEN "\x1b[47;42m"
#define DEFAULT "\x1b[0m"

class Level
{
public:
    Level(std::string name);

    void Load(std::string name);

    void Print();

private:
    std::string name;

    ObjectFactory *objectFactory;

    Grid *grid;
    std::vector<Object *> objectVector;
};