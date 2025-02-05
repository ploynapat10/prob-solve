#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcs(string s, string t) {
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLen = 0;

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
                maxLen = max(maxLen,dp[i][j]);
            } else {
                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return maxLen;
}

int main() {
    string S, T;
    cin >> S >> T;

    int result = lcs(S, T);
    cout << result << endl;

    return 0;
}
