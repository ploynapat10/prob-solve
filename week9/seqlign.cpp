#include<bits/stdc++.h>
using namespace std;

stack<char> st;
int main(){
    string s, t;
    int i,j;
    cin >> s >> t;
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for (int i=1; i<=m; i++) {
        dp[i][0] = i;
    }
    for(i=1;i<=n;i++){
        dp[0][i] = i;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            int match, del, ins;
            if(s[i-1]==t[j-1]){
                match = dp[i-1][j-1];
            }
            else{
                match = dp[i-1][j-1]+1;
            }
            del = dp[i-1][j] + 1;
            ins = dp[i][j-1] + 1;
            dp[i][j] = min(match,min(del,ins));
        }
    }
    cout << dp[m][n] << "\n";
}