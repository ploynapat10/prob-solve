#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> topological_sort(unordered_map<int, vector<int>>& graph, int n) {
    vector<int> indegree(n + 1, 0);
    for (auto& kvp : graph) {
        for (int neighbor : kvp.second) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
        }

        vector<int> order = topological_sort(graph, n);
        for (int i = 0; i < n; ++i) {
            cout << order[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
