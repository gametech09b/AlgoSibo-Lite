#include "Level.hpp"

Level::Level(std::string filePath, std::string name)
{
    this->name = name;

    std::vector<std::vector<Cell *>> grid;

    std::vector<Object *> objectVector;

    std::vector<std::string> fileContent = FileHandler::ReadFile(filePath);
    if (fileContent.size() > 0)
    {
        int index = 0;

        while (index < fileContent.size() - 1)
        {
            std::string line = fileContent[index];

            if (line.find("CO") != std::string::npos)
            {
                // std::cout << "CO found." << std::endl;

                std::vector<std::string> splittedLine = FileHandler::SplitLine(line, ' ');

                std::string objectName = splittedLine[1];
                int x = std::stoi(splittedLine[2]);
                int y = std::stoi(splittedLine[3]);
                std::string direction = splittedLine[4];

                if (direction == "UP")
                {
                    objectVector.push_back(
                        ObjectFactory::CreateObject(objectName, new Position(x, y), Direction::UP));
                }
                else if (direction == "DOWN")
                {
                    objectVector.push_back(
                        ObjectFactory::CreateObject(objectName, new Position(x, y), Direction::DOWN));
                }
                else if (direction == "LEFT")
                {
                    objectVector.push_back(
                        ObjectFactory::CreateObject(objectName, new Position(x, y), Direction::LEFT));
                }
                else if (direction == "RIGHT")
                {
                    objectVector.push_back(
                        ObjectFactory::CreateObject(objectName, new Position(x, y), Direction::RIGHT));
                }
                else
                {
                    std::cout << "Error: Invalid direction" << std::endl;
                    continue;
                }

                index++;
                // std::cout << "Object created" << std::endl;
            }
            // else
            // {
            //     std::cout << "Error: CO not found in file" << std::endl;
            //     i++;
            // }

            if (line.find("MAP") != std::string::npos)
            {
                // std::cout << "MAP found." << std::endl;

                int x = 0;
                int y = 0;

                index = index + 1;

                bool isMapping = true;
                while (isMapping)
                {
                    std::string line = fileContent[index];

                    std::vector<Cell *> row;

                    if (line.find("END") != std::string::npos)
                    {
                        // std::cout << "END found." << std::endl;
                        isMapping = false;
                        break;
                    }
                    else
                    {
                        std::vector<std::string> splittedLine = FileHandler::SplitLine(line, ' ');

                        for (std::string cell : splittedLine)
                        {
                            if (cell == "0")
                            {
                                row.push_back(new Cell(new Position(x, y), false));
                            }
                            else if (cell == "1")
                            {
                                row.push_back(new Cell(new Position(x, y), true));
                            }
                            else
                            {
                                std::cout << "Error: Invalid cell value" << std::endl;
                                continue;
                            }

                            x++;
                        }

                        // std::cout << "Row created" << std::endl;
                        grid.push_back(row);

                        y++;

                        index++;
                    }
                }
            }
            // else
            // {
            //     std::cout << "Error: MAP not found in file" << std::endl;
            //     i++;
            // }
        }

        this->grid = new Grid(grid);
        this->objectVector = objectVector;
        this->currentControllableObject = this->objectVector[0];

        FileHandler::ClearFile();
    }
}

std::string Level::GetName()
{
    return this->name;
}

Grid *Level::GetGrid()
{
    return this->grid;
}

std::vector<Object *> Level::GetObjectVector()
{
    return this->objectVector;
}

Object *Level::GetCurrentControllableObject()
{
    return this->currentControllableObject;
}

void Level::SetCurrentControllableObject(int index)
{
    this->currentControllableObject = this->objectVector[index];
}