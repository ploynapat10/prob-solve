#include<bits/stdc++.h>
using namespace std;

int dp[210][210];
stack<char> st;
int main(){
    string s, t;
    int i,j;
    cin >> s >> t;
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
    cout << dp[m][n] << "\n";
    i = m;
    j = n;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            st.push(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{j--;
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}