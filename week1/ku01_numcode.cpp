#include <iostream>
using namespace std;

int main() {
    int N, T;

    cin >> N >> T;

    int arr[550], y[550], x[550];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if (T == 2) {
        y[0] = arr[0];
        for (int i = 1; i < N; i++) {
            int dis1 = abs(arr[i] - 2 * y[i - 1]);
            int dis2 = abs(arr[i] - 3 * y[i - 1]);
            if (dis1 < dis2) {
                y[i] = arr[i] - y[i - 1];
            } else {
                y[i] = arr[i] - (2 * y[i - 1]);
            }
        }

        if (y[0] == N - 1) {
            x[0] = 0;
        } else if (y[0] == N + 1) {
            x[0] = 1;
        }

        for (int i = 1; i <= N; i++) {
            if (y[i] == y[i - 1] - 1) {
                x[i] = 0;
            } else if (y[i] == y[i - 1] + 1) {
                x[i] = 1;
            }
        }

    } else {
        if (arr[0] == N - 1) {
            x[0] = 0;
        } else if (arr[0] == N + 1) {
            x[0] = 1;
        }

        for (int i = 1; i <= N; i++) {
            if (arr[i] == arr[i - 1] - 1) {
                x[i] = 0;
            } else if (arr[i] == arr[i - 1] + 1) {
                x[i] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << x[i] << endl;
    }
    return 0;
}