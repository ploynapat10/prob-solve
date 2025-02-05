#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, const vector<int>& prices, const vector<int>& weights) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + prices[i - 1]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> prices(N);
        vector<int> weights(N);

        for (int i = 0; i < N; ++i) {
            cin >> prices[i] >> weights[i];
        }

        int G;
        cin >> G;

        int maxTotalValue = 0;

        for (int i = 0; i < G; ++i) {
            int MW;
            cin >> MW;
            maxTotalValue += knapsack(MW, prices, weights);
        }

        cout << maxTotalValue << endl;
    }

    return 0;
}