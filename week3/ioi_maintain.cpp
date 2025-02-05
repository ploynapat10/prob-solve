#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Trail {
    int start, end, length;
};

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        parent[py] = px;
    }
};

int main() {
    int N, W;
    cin >> N >> W;

    DSU dsu(N);
    vector<Trail> trails;

    for (int i = 0; i < W; ++i) {
        int start, end, length;
        cin >> start >> end >> length;

        trails.push_back({start, end, length});

        // Union the fields connected by the new trail
        dsu.unite(start, end);

        // Check if all fields are connected
        bool allConnected = true;
        int representative = dsu.find(1);
        for (int j = 2; j <= N; ++j) {
            if (dsu.find(j) != representative) {
                allConnected = false;
                break;
            }
        }

        if (allConnected) {
            int totalLength = 0;
            for (const auto& trail : trails) {
                totalLength += trail.length;
            }
            cout << totalLength << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
