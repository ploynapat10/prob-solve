#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Car {
    int price;
    int performance;
};

bool compareCars(const Car& a, const Car& b) {
    return a.performance > b.performance;
}

int main() {
    int N;
    cin >> N;

    vector<Car> cars(N);

    for (int i = 0; i < N; ++i) {
        cin >> cars[i].price >> cars[i].performance;
    }

    sort(cars.begin(), cars.end(), compareCars);

    int unsellableCars = 0;
    int maxPrice = cars[0].price;

    for (int i = 1; i < N; ++i) {
        if (cars[i].price >= maxPrice) {
            unsellableCars++;
        } else {
            maxPrice = cars[i].price;
        }
    }

    cout << unsellableCars << endl;

    return 0;
}