#include<bits/stdc++.h>
using namespace std;

map<int, int> like;

int main(){
    int n, x, mx = -2e9, mxans;
    cin >> n;
    while(n!=0){
        cin >> x;
        if(like.find(x)!=like.end()){
            like[x]++;
        }
        else{
            like[x] = 1;
        }
        if(like[x]>=mx){
            mx = like[x];
            mxans = x;
        }
        cout << mxans << endl;
        n--;
    }
}