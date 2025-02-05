#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long minMaxPenalty(vector<pair<int, int>>& jobs) {
    sort(jobs.begin(), jobs.end());

    long long maxPenalty = 0;
    long long cumulativeTime = 0;

    for (const auto& job : jobs) {
        cumulativeTime += job.second;
        maxPenalty = max(maxPenalty, max(0LL, cumulativeTime - job.first - 10));
    }

    return maxPenalty * 1000; // Penalty rate is 1000 baht per day
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> jobs(N);

    for (int i = 0; i < N; ++i) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    long long result = minMaxPenalty(jobs);

    cout << result << endl;

    return 0;
}
