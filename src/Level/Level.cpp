#include "Level.hpp"

Level::Level(std::string name)
{
    this->name = name;

    this->objectFactory = new ObjectFactory();
    this->grid = new Grid(2, 10);

    Object *player = this->objectFactory->CreateObject("NormalRabbid", new Position(0, 0), Direction::LEFT);
    this->objectVector.push_back(player);
}

void Level::Load(std::string name)
{
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
                std::cout << "|";
                Cell *currentCell = grid->GetCell(new Position(x, y));

                if (currentCell->GetIsWalkable())
                {
                    if (objectVector[0]->GetDirection() == Direction::UP && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                        std::cout << GREEN << "   ^   " << DEFAULT;
                    else
                        std::cout << GREEN << "       " << DEFAULT;
                }
                else
                {
                    if (objectVector[0]->GetDirection() == Direction::UP && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
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
                std::cout << "|";
                if (grid->GetCell(new Position(x, y))->GetIsWalkable())
                {
                    if (objectVector[0]->GetDirection() == Direction::LEFT && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                    {
                        std::cout << GREEN << "  <";
                        objectVector[0]->Print();
                        std::cout << "   " << DEFAULT;
                    }
                    else if (objectVector[0]->GetDirection() == Direction::RIGHT && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                    {
                        std::cout << GREEN << "   ";
                        objectVector[0]->Print();
                        std::cout << ">  " << DEFAULT;
                    }
                    else if (objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                    {
                        std::cout << GREEN << "   ";
                        objectVector[0]->Print();
                        std::cout << "   " << DEFAULT;
                    }
                    else
                    {
                        std::cout << GREEN << "       " << DEFAULT;
                    }
                }
                else
                {
                    if (objectVector[0]->GetDirection() == Direction::LEFT && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                    {
                        std::cout << RED << "  <";
                        objectVector[0]->Print();
                        std::cout << "   " << DEFAULT;
                    }
                    else if (objectVector[0]->GetDirection() == Direction::RIGHT && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                    {
                        std::cout << RED << "   ";
                        objectVector[0]->Print();
                        std::cout << ">  " << DEFAULT;
                    }
                    else if (objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                    {
                        std::cout << RED << "   ";
                        objectVector[0]->Print();
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
                std::cout << "|";
                if (grid->GetCell(new Position(x, y))->GetIsWalkable())
                {
                    if (objectVector[0]->GetDirection() == Direction::DOWN && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
                        std::cout << GREEN << "   v   " << DEFAULT;
                    else
                        std::cout << GREEN << "       " << DEFAULT;
                }
                else
                {
                    if (objectVector[0]->GetDirection() == Direction::DOWN && objectVector[0]->GetPosition().x == x && objectVector[0]->GetPosition().y == y)
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