#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vecx(n);
    for (int i = 0; i < n; ++i) {
        cin >> vecx[i];
    }

    sort(vecx.begin(), vecx.end());

    for (int i = 0; i < m; ++i) {
        int y;
        cin >> y;

        auto lower = lower_bound(vecx.begin(), vecx.end(), y); 
        if (lower == vecx.begin()) {
            cout << *lower << endl;
        } else if (lower == vecx.end()) {
            cout << *(--lower) << endl;
        } else {
            auto prev = lower;
            --prev;
            if (abs(*lower - y) < abs(*prev - y)) {
                cout << *lower << endl;
            } else {
                cout << *prev << endl;
            }
        }
    }

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n,m,x,y;
//     cin >> n >> m;

//     vector<int> vecx(n);
//     for(int i=0;i<n;i++){
//         cin >> x;
//         vecx.push_back(x);
//     }
//     sort(vecx.begin(), vecx.end());

//     for(int i=0;i<m;i++){
//         cin >> y;
//         auto lower = lower_bound(vecx.begin(),vecx.end(),y);
//         if (lower == vecx.begin()) {
//             cout << *lower << endl; 
//         }
//         else if (lower == vecx.end()) {
//             cout << *(--lower) << endl;
//             auto prev = lower;
//             --prev;
//             if (abs(*lower - y) <= abs(*prev - y)) {
//                 cout << *lower << endl;
//             } else {
//                 cout << *prev << endl;
//             }
//         }
        
//     }
// }