#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100005];
bool isBipartite(vector<int> adj[], int V) {
    vector<int> color(V+1, -1);
    for (int i = 1; i <= V; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                //cout << u << endl;

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    while(k--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i <= n; i++) {
            adj[i].clear();
        }

        int u, v;

        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isBipartite(adj, n))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}