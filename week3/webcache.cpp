#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cache;
    unordered_set<int> cacheSet;
    int misses = 0;

    for (int i = 0; i < m; ++i) {
        int page;
        cin >> page;

        if (cacheSet.find(page) == cacheSet.end()) {
            ++misses;
            if (cache.size() == n) {
                int oldestPage = cache.front();
                cacheSet.erase(oldestPage);
                cache.erase(cache.begin());
            }
            cache.push_back(page);
            cacheSet.insert(page);
        }
    }

    cout << misses << endl;

    return 0;
}
