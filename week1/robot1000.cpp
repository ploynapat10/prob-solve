#include <iostream>
using namespace std;

int main() {
    int x = 0, y = 0;

    char direction;

    while (cin.get(direction) && direction != '\n') {
        if (direction == 'N') {
            y++;
        } else if (direction == 'S') {
            y--;
        } else if (direction == 'E') {
            x++;
        } else if (direction == 'W') {
            x--;
        } else if (direction == 'Z') {
            x = 0;
            y = 0;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}