#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> l;
  int n, i, num;
  char opr;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> opr >> num;
    if (opr == 'I') {
      l.push_front(num);
    }
    if (opr == 'D') {
      auto j = l.begin();
      advance(j, num-1);
      if (num <= l.size()) {
        l.erase(j);
      }
    }
  }
  for (auto i = l.begin(); i != l.end(); i++) {
    cout << *i << endl;
  }
}