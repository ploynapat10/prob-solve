#include <iostream>
using namespace std;
int a[100100],mx[100100];

int main() {
    int n;
    a[0] = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    mx[0]=0,mx[1]=0,mx[2]=0;
    for(int i=3;i<=n;i++){
        if(a[i]+mx[i-3]>mx[i-1]){
            mx[i]=a[i]+mx[i-3];
        }
        else{
            mx[i]=mx[i-1];
        }
    }
    cout << mx[n];
    return 0;
}