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
                std::cout << "CO found." << std::endl;

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
                std::cout << "Object created" << std::endl;
            }
            // else
            // {
            //     std::cout << "Error: CO not found in file" << std::endl;
            //     i++;
            // }

            if (line.find("MAP") != std::string::npos)
            {
                std::cout << "MAP found." << std::endl;

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
                        isMapping = false;
                        std::cout << "END found." << std::endl;
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

                        grid.push_back(row);

                        y++;
                        std::cout << "Row created" << std::endl;

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

void Level::Print()
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < grid->GetWidth() * 4; i++)
    {
        if (i % 4 == 0)
        {
            for (int j = 0; j < grid->GetHeight(); j++)
            {
                std::cout << "|";
                std::cout << "=======";
            }
            std::cout << "|";
        }

        if (i % 4 == 1)
        {
            for (int j = 0; j < grid->GetHeight(); j++)
            {
                Cell *currentCell = grid->GetCell(new Position(x, y));
                Object *currentObject = objectVector[0];

                std::cout << "|";

                if (currentCell->GetIsWalkable())
                {
                    if (currentObject->GetDirection() == Direction::UP && currentObject->GetPosition() == Position(x, y))
                        std::cout << GREEN << "   ^   " << DEFAULT;
                    else
                        std::cout << GREEN << "       " << DEFAULT;
                }
                else
                {
                    if (currentObject->GetDirection() == Direction::UP && currentObject->GetPosition() == Position(x, y))
                        std::cout << RED << "   ^   " << DEFAULT;
                    else
                        std::cout << RED << "       " << DEFAULT;
                }
                y++;
            }
            std::cout << "|";
            y = 0;
        }

        if (i % 4 == 2)
        {
            for (int j = 0; j < grid->GetHeight(); j++)
            {
                Cell *currentCell = grid->GetCell(new Position(x, y));
                Object *currentObject = objectVector[0];

                std::cout << "|";

                if (currentCell->GetIsWalkable())
                {
                    if (currentObject->GetDirection() == Direction::LEFT && currentObject->GetPosition() == Position(x, y))
                    {
                        std::cout << GREEN << " < ";
                        currentObject->Print();
                        std::cout << "   " << DEFAULT;
                    }
                    else if (currentObject->GetDirection() == Direction::RIGHT && currentObject->GetPosition() == Position(x, y))
                    {
                        std::cout << GREEN << "   ";
                        currentObject->Print();
                        std::cout << " > " << DEFAULT;
                    }
                    else if (currentObject->GetPosition() == Position(x, y))
                    {
                        std::cout << GREEN << "   ";
                        currentObject->Print();
                        std::cout << "   " << DEFAULT;
                    }
                    else
                    {
                        std::cout << GREEN << "       " << DEFAULT;
                    }
                }
                else
                {
                    if (currentObject->GetDirection() == Direction::LEFT && currentObject->GetPosition() == Position(x, y))
                    {
                        std::cout << RED << " < ";
                        currentObject->Print();
                        std::cout << "   " << DEFAULT;
                    }
                    else if (currentObject->GetDirection() == Direction::RIGHT && currentObject->GetPosition() == Position(x, y))
                    {
                        std::cout << RED << "   ";
                        currentObject->Print();
                        std::cout << " > " << DEFAULT;
                    }
                    else if (currentObject->GetPosition() == Position(x, y))
                    {
                        std::cout << RED << "   ";
                        currentObject->Print();
                        std::cout << "   " << DEFAULT;
                    }
                    else
                    {
                        std::cout << RED << "       " << DEFAULT;
                    }
                }
                y++;
            }
            std::cout << "|";
            y = 0;
        }

        if (i % 4 == 3)
        {
            for (int j = 0; j < grid->GetHeight(); j++)
            {
                Cell *currentCell = grid->GetCell(new Position(x, y));
                Object *currentObject = objectVector[0];

                std::cout << "|";

                if (currentCell->GetIsWalkable())
                {
                    if (currentObject->GetDirection() == Direction::DOWN && currentObject->GetPosition() == Position(x, y))
                        std::cout << GREEN << "   v   " << DEFAULT;
                    else
                        std::cout << GREEN << "       " << DEFAULT;
                }
                else
                {
                    if (currentObject->GetDirection() == Direction::DOWN && currentObject->GetPosition() == Position(x, y))
                        std::cout << RED << "   v   " << DEFAULT;
                    else
                        std::cout << RED << "       " << DEFAULT;
                }
                y++;
            }
            std::cout << "|";
            y = 0;
            x++;
        }

        std::cout << std::endl;
    }

    for (int j = 0; j < grid->GetHeight(); j++)
    {
        std::cout << "|";
        std::cout << "=======";
    }
    std::cout << "|";
}