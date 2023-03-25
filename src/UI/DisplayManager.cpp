#include "DisplayManager.hpp"

void DisplayManager::PrintLevel(Level *level)
{
    Grid *grid = level->GetGrid();
    std::vector<Object *> objectVector = level->GetObjectVector();

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