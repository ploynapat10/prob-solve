#include <iostream>
#include <list>

using namespace std;

int main() {
    string s;
    while (getline(cin, s) && !s.empty()) {
        list<char> L;
        auto curr = L.begin();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') curr = L.begin();
            else if (s[i] == ']') curr = L.end();
            else {
                curr = L.insert(curr, s[i]);
                curr++;
            }
        }
        for (curr = L.begin(); curr != L.end(); curr++) {
            cout << *curr;
        }
        cout << endl;
    }
}