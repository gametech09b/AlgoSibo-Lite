#include <iostream>
#include <vector>

using namespace std;

class Character {
private:
    static Character* instance;
    int x, y;
    int spawnX, spawnY;
    int finishX, finishY;
    vector<pair<int, int>> path;
    int pathIndex;
    int score;

    Character() {
        x = 0;
        y = 0;
        spawnX = 0;
        spawnY = 0;
        finishX = 10;
        finishY = 10;
        path = generatePath(spawnX, spawnY, finishX, finishY);
        pathIndex = 0;
        score = 0;
    } // constructor private

    vector<pair<int, int>> generatePath(int startX, int startY, int endX, int endY) {
        vector<pair<int, int>> path;
        int dx = endX - startX;
        int dy = endY - startY;
        int steps = max(abs(dx), abs(dy));
        float xIncrement = (float) dx / steps;
        float yIncrement = (float) dy / steps;
        float x = startX;
        float y = startY;
        for (int i = 0; i <= steps; i++) {
            path.push_back(make_pair((int) x, (int) y));
            x += xIncrement;
            y += yIncrement;
        }
        return path;
    }

public:
    static Character* getInstance() {
        if (instance == nullptr) {
            instance = new Character();
        }
        return instance;
    }

    void moveUp() {
        if (y > 0) {
            y--;
            checkPath();
        }
    }

    void moveDown() {
        if (y < 19) {
            y++;
            checkPath();
        }
    }

    void moveLeft() {
        if (x > 0) {
            x--;
            checkPath();
        }
    }

    void moveRight() {
        if (x < 19) {
            x++;
            checkPath();
        }
    }

    void setSpawnPoint(int x, int y) {
        spawnX = x;
        spawnY = y;
        path = generatePath(spawnX, spawnY, finishX, finishY);
        pathIndex = 0;
        score = 0;
    }

    void setFinishPoint(int x, int y) {
        finishX = x;
        finishY = y;
        path = generatePath(spawnX, spawnY, finishX, finishY);
        pathIndex = 0;
        score = 0;
    }

    bool hasReachedFinishPoint() {
        return x == finishX && y == finishY;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getScore() {
        return score;
    }

    void checkPath() {
        if (pathIndex < path.size() && path[pathIndex].first == x && path[pathIndex].second == y) {
            pathIndex++;
            score++;
        }
    }
};

Character* Character::instance = nullptr; // initialize instance ke nullptr

int main()
{
    char input;
    Character* character = Character::getInstance();

    // Set the spawn and finish points
    character->setSpawnPoint(0, 0);
    character->setFinishPoint(10, 10);

    while (true) {
        // clear the console
        system("cls");

        // display grid system
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == character->getY() && j == character->getX()) {
                    cout << "O ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << endl;
        }

        cout << "posisi karakter: (" << character->getX() << ", " << character->getY() << ")" << endl;

        // Check if the character has reached the finish point
        if (character->hasReachedFinishPoint()) {
            cout << "Selamat, Anda telah mencapai finish point!" << endl;
            break;
        }

        // cek input
        cin >> input;

        switch (input) {
        case 'w':
            character->moveUp();
            break;
        case 's':
            character->moveDown();
            break;
        case 'a':
            character->moveLeft();
            break;
        case 'd':
            character->moveRight();
            break;
        }

        _sleep(100);
    }

    // Move the character
    // ...

    return 0;
}
