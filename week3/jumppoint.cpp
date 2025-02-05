#include <iostream>
#include <cmath>
#include <queue>
#define MAX_N 1010

using namespace std;

int g[MAX_N][MAX_N];
pair<int,int> a[MAX_N];
int dis[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, j, n, r;
    cin >> n >> r;
    for (i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a[n].first = 0; a[n].second = 0;
    a[n + 1].first = 100; a[n + 1].second = 100;
    for (i = 0; i < n + 2; i++) {
        for (j = i + 1; j < n + 2; j++) {
            if (r * r >= (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second)) {
                g[i][j] = g[j][i] = 1;
            }
        }
    }
    dis[n] = 0;
    dis[n + 1] = -1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int x = 0; x < n + 2; x++) {
            if (g[now][x] && dis[x] == 0) {
                dis[x] = dis[now] + 1;
                q.push(x);
            }
        }
    }
    cout << dis[n + 1] << "\n";
    return 0;
}
