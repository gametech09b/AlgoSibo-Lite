#pragma once

#include <fstream>
#include <sstream>
#include <vector>

class FileHandler
{
public:
    static std::vector<std::string> ReadFile(std::string filePath);
    static void WriteFile(std::string filePath);
    static void AddLine(std::string line);
    static void ClearFile();
    static std::vector<std::string> GetFileContent();
    static std::vector<std::string> SplitLine(std::string line, char delimiter);

private:
    static std::vector<std::string> fileContent;
};