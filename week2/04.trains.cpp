#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> train[100100];
    int n,num1,num2;
    char opr;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> opr >> num1 >> num2;
        if(opr=='N'){
            train[num2].push_back(num1);
        }
        else if(opr=='M'){
            train[num2].splice(train[num2].end(),train[num1]);
            train[num1].clear();
        }
    }
    for(int i=0;i<100000;i++){
        if(train[i].size()!=0);
        for(auto j=train[i].begin();j!=train[i].end();j++){
            cout << *j << endl;
        }
    }

    return 0;
}