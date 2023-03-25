#pragma once

#include "../Level/Level.hpp"

#define RED "\x1b[47;41m"
#define GREEN "\x1b[47;42m"
#define DEFAULT "\x1b[0m"

class DisplayManager
{
public:
    static void PrintLevel(Level *level);
};