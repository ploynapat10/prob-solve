#include<iostream>
#include<stack>

using namespace std;

int main() {
    int n, car, cur, flag;
    stack<int> s;
    while (cin >> n) {
        if (n <= 0) break;
        while (cin >> car) {
            if (car <= 0) break;
            cur = 1;
            flag = 1;
            while(!s.empty()) s.pop();
            for (int i = 1; i < n; i++) {
                for(; cur <= car; cur++) {
                    s.push(cur);
                }

                if (s.top() != car) {
                    flag = 0;
                }

                s.pop();

                cin >> car && car;
            }

            if (flag) cout << "Yes" << endl;
            else cout << "No" << endl;

        }

        cout << endl;

    }

}