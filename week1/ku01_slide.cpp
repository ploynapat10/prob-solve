#include <iostream>
using namespace std;

int arr[50];

int main() {
    int N;
    int passes = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                passes += 1;
            }
        }
    }
    cout << passes;
}