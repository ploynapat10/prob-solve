#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int mem[100100][300];

int n, k;
int dp(int idx, int x, int y, vector<int> &a, vector<int> &b)
{
    if (abs(x - y) > k)
    {
        return 1000000000;
    }
    if (idx == n)
    {
        cout << x << " " << y << endl;
        return 0;
    }
    if (mem[idx][x - y + 110] != -1)
    {
        return mem[idx][x - y + 110];
    }
    int res1 = dp(idx + 1, x + 1, y, a, b) + a[idx];
    int res2 = dp(idx + 1, x, y + 1, a, b) + b[idx];
    return mem[idx][x - y + 110] = min(res1, res2);
}

int main()
{
    int c;
    cin >> c;
    for (int notuse = 0; notuse < c; notuse++)
    {
        for (int i = 0; i < 100100; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                mem[i][j] = -1;
            }
        }
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        cout << dp(0, 0, 0, a, b) << endl;
    }
}