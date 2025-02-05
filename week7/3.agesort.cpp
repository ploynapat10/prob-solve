#include <bits/stdc++.h>
using namespace std;

long long total = 0;
vector<int> mergesort(vector<int>& arr) {
    if (arr.size() <= 1){
        return arr;
    }

    vector<int> left(arr.begin(), arr.begin() + arr.size()/2);
    vector<int> right(arr.begin() + arr.size()/2, arr.end());

    left = mergesort(left);
    right = mergesort(right);

    vector<int> res;
    size_t l=0, r=0;
    while (l<left.size() && r<right.size()) {
        if (left[l]<right[r]) {
            res.push_back(left[l]);
            l+=1;
        } else {
            res.push_back(right[r]);
            r+=1;
            total += left.size()-l;
        }
    }
    while (l<left.size()) {
        res.push_back(left[l]);
        l+=1;
    }
    while (r<right.size()) {
        res.push_back(right[r]);
        r+=1;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    total = 0;
    vector<int> answer = mergesort(arr);
    cout << total;
}