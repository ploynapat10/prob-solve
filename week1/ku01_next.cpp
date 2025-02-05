#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int playerNumbers[N];
    int playerItems[N];
    bool playerReceivedOwnNumber[N];

    for (int i = 0; i < N; i++) {
        cin >> playerNumbers[i];
        playerItems[i] = i + 1;
        playerReceivedOwnNumber[i] = false;
    }

    int turns = 0;

    while (true) {
        int newPlayerItems[N];

        for (int i = 0; i < N; i++) {
            int receiver = playerNumbers[i] - 1;
            newPlayerItems[receiver] = playerItems[i];
        }

        for (int i = 0; i < N; i++) {
            playerItems[i] = newPlayerItems[i];
            if (playerItems[i] == i + 1) playerReceivedOwnNumber[i] = true;
        }

        turns++;

        for (int i = 0; i < N; i++) {
            if (!playerReceivedOwnNumber[i]) break;
            if (i == N - 1) {
                cout << turns << endl;
                return 0;
            }
        }
    }
}