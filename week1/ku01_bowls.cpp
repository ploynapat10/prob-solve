#include <iostream>
using namespace std;

int main() {
    int n,i,mx=-99999,sum=0;
    int arr[310];
    cin >> n;
    for(i=0;i<310;i++){
        arr[i]=0;
    }
    for(i=0;i<n;i++){
        int x;
        cin >> x;
        arr[x]++;
        if(arr[x]>mx){
            mx = arr[x];
        }
    }
    cout << mx;
    return 0;
}