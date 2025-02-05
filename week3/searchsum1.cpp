#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;
long long book[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long price;
        cin >> price;
        total += price;
        book[i] = total;
    }

    while (k!=0) {
        long long money;
        cin >> money;
        
        if (money >= book[n - 1]) {
            cout << n << "\n";
        } else {
            int idx = upper_bound(book, book + n, money) - book;
            cout << idx << "\n";
        }
        k--;
    }
}