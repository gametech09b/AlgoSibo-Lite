#include "FileHandler.hpp"

std::vector<std::string> FileHandler::ReadFile(std::string filePath)
{
    std::vector<std::string> fileContent;

    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line))
    {
        fileContent.push_back(line);
    }

    file.close();

    return fileContent;
}

void FileHandler::WriteFile(std::string filePath)
{
    std::ofstream file(filePath);
    for (int i = 0; i < fileContent.size(); i++)
    {
        file << fileContent[i] << std::endl;
    }

    file.close();
}

void FileHandler::AddLine(std::string line)
{
    fileContent.push_back(line);
}

void FileHandler::ClearFile()
{
    fileContent.clear();
}

std::vector<std::string> FileHandler::GetFileContent()
{
    return fileContent;
}

std::vector<std::string> FileHandler::SplitLine(std::string line, char delimiter)
{
    std::vector<std::string> splittedLine;
    std::string data;

    std::stringstream ss(line);

    while (std::getline(ss, data, delimiter))
    {
        splittedLine.push_back(data);
    }

    return splittedLine;
}

std::vector<std::string> FileHandler::fileContent;