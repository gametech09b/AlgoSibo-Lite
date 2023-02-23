#pragma once

#include "Cell.hpp"
#include <vector>
#include <string>

class FileHandler
{
public:
    void ReadFile(char *fileName);
    void WriteFile(char *fileName);
    void AddLine(char *line);
    void ClearFile();

private:
    std::vector<std::string> _fileContent;
};