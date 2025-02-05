#include<bits/stdc++.h>
using namespace std;

map<int, int> product;

int main(){
    int m, fnc, type, n;
    cin >> m;
    while(m--){
        cin >> fnc;
        if(fnc==1){
            cin >> type >> n;
            if(product.find(type)!=product.end()){
                product[type] += n;
            }
            else{
                product[type] = n;
            }
        }
        else if(fnc==2){
            cin >> type;
            if(product.find(type)!=product.end()){
                cout << product[type] << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(fnc==3){
            cin >> type >> n;
            if(product.find(type)!=product.end()){
                if(product[type]-n>=0){
                    product[type]-=n;
                    cout << n << endl;
                }
                else{
                    cout << product[type]  << endl;
                    product[type] = 0;
                }
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}