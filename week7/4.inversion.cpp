#include <bits/stdc++.h>
using namespace std;

long long inversionCount = 0;

vector<int> Msort(vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    vector<int> right(arr.begin() + arr.size() / 2, arr.end());

    left = Msort(left);
    right = Msort(right);

    vector<int> result;
    size_t l = 0, r = 0;
    while (l < left.size() && r < right.size()) {
        if (left[l] <= right[r]) {
            result.push_back(left[l]);
            l++;
        } else {
            result.push_back(right[r]);
            r++;
            inversionCount += left.size() - l;
        }
    }
    while (l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    while (r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;
        vector<int> arr(x);
        for (int i = 0; i < x; i++) {
            cin >> arr[i];
        }
        inversionCount = 0; 
        vector<int> sorted = Msort(arr);
        
        cout << inversionCount << endl;

    return 0;
}