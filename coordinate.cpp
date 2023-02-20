#include <iostream>

using namespace std;

class Character {
private:
    static Character* instance;
    int x, y;
    Character() {
        x = 0;
        y = 0;
    } // constructor private
public:
    static Character* getInstance() {
        if (instance == nullptr) {
            instance = new Character();
        }
        return instance;
    }

    void moveUp() {
        y--;
    }

    void moveDown() {
        y++;
    }

    void moveLeft() {
        x--;
    }

    void moveRight() {
        x++;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

Character* Character::instance = nullptr; // initialize instance ke nullptr

int main()
{
    char input;
    Character* character = Character::getInstance();

    while (true) {
        // clear the console
        system("cls");

        // display posisi karakter
        for (int i = 0; i < character->getY(); i++) {
            cout << endl;
        }
        for (int i = 0; i < character->getX(); i++) {
            cout << " ";
        }
        cout << "O";
        cout << endl << "posisi karakter: (" << character->getX() << ", " << character->getY() << ")" << endl;

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

    return 0;
}
