#include <iostream>
using namespace std;
int a[1010],l[1010],l_from[1010],arres[1010];

int main() {
  int n;
  cin >> n;
  a[0]=-2e9, l[0]=0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  int mx=-2e9, res;
  for(int i=1;i<=n;i++){
    for(int j=i-1;j>=0;j--){
      if(a[i]>a[j]){
        if(l[j]+1>l[i]){
          l[i]=l[j]+1;
          l_from[i]=j;
          if(l[i]>mx){
            mx=l[i];
            res=i;
          }
        }
      }
    }
  }
  cout << mx << "\n";
    int i = res, j = mx;
    while(i!=0){
        arres[j--] = a[i];
        i = l_from[i];
    }
    for(int i=1;i<=mx;i++){
      cout << arres[i];
      if(i!=mx){
        cout << " ";
      }
    }

  return 0;
}