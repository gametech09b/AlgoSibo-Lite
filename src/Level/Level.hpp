#pragma once

#include "../FileSystem/FileHandler.hpp"
#include "../Grid/Grid.hpp"
#include "../Grid/Cell/Cell.hpp"
#include "../Object/Object.hpp"
#include "../Object/ObjectFactory.hpp"
#include <iostream>
#include <string>
#include <vector>

class Level
{
public:
    Level(std::string filePath, std::string name);

    std::string GetName();
    Grid *GetGrid();
    std::vector<Object *> GetObjectVector();
    Object *GetCurrentControllableObject();
    void SetCurrentControllableObject(int index);

private:
    std::string name;

    Grid *grid;

    std::vector<Object *> objectVector;
    Object *currentControllableObject;
};