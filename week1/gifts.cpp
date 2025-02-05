#include <iostream>
using namespace std;

int main() {
    int n;
    int sum=0;
    int x,i;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x;
        if(x>0){
            sum+=x;
        }
    }
    cout << sum;
    return 0;
}