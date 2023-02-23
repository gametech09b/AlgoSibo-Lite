#include "./headers/FileSystem/FileHandler.hpp"
#include <fstream>
#include <vector>
#include <string>

void FileHandler::ReadFile(char *fileName)
{
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line))
    {
        _fileContent.push_back(line);
    }
}

void FileHandler::WriteFile(char *fileName)
{
    std::ofstream file(fileName);
    for (int i = 0; i < _fileContent.size(); i++)
    {
        file << _fileContent[i] << std::endl;
    }
}

void FileHandler::AddLine(char *line)
{
    _fileContent.push_back(line);
}

void FileHandler::ClearFile()
{
    _fileContent.clear();
}
