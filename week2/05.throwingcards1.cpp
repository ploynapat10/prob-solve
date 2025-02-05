#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> l;
  int n=1, i;
  bool x = true;
  while(x){
    cin >> n;
    if(n==0){
      break;
    }
    for(i=0;i<n;i++){
        l.push_back(i+1);
    }
    cout << "Discarded cards:";
    while(l.size()!=1){
        cout << " " << l.front();
        if(l.size()>2){
            cout << ",";
        }
        l.pop_front();
        l.push_back(l.front());
        l.pop_front();
    }
    cout << "\n" << "Remaining card: " << l.front() << "\n";
    l.pop_front();
  }
}