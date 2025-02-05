#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,total;
    cin >> n;
    vector<int> h;
    for(int i=0;i<n;i++){
        cin >> x;
        h.push_back(x);
    }
    total = 0;
    for(int i=0;i<n;i++){
        if(h[i]<h[i-1] || h[i]<h[i+1]){
            total+=1;
        }
    }
    cout << total;
}