#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int c = 1; c <= n; ++c) {
        int x, h, ta, td;
        cin >> x >> h >> ta >> td;

        vector<int> heights(x);
        for (int i = 0; i < x; ++i)
            cin >> heights[i];

        sort(heights.begin(), heights.end());

        int minTime = INT_MAX;

        for (int i = 0; i < x; ++i) {
            int currentHeight = heights[i];
            int time = ta * i;
            int remainingHeight = h - currentHeight;

            int j = lower_bound(heights.begin(), heights.end(), remainingHeight) - heights.begin();

            if (j < x && j != i) {
                time += td * (x - j);
            } else {
                time += ta * (x - i);
            }

            minTime = min(minTime, time);
        }

        cout << "Case " << c << ": " << minTime << endl;
    }

    return 0;
}
