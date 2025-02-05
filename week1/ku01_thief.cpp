#include <iostream>
using namespace std;

int main() {
    int N, K, T;
    int curr_person = 1;
    int checked_person = 0;

    cin >> N >> K >> T;

    int checked_gift[N + 5] = {0};

    while (true) {
        if (checked_gift[curr_person] == 0) {
            checked_gift[curr_person] = 1;
            checked_person += 1;
        }
        if (curr_person == T) {
            break;
        }
        if (curr_person == 1 && checked_person != 1) {
            break;
        }
        curr_person = (curr_person + K - 1) % N + 1;
    }

    cout << checked_person << endl;
}