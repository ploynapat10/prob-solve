#include <iostream>
using namespace std;

int arr[100100];

int main() {
  long long n,rnd,i,minute;
  long long mn = 2e9;
  
  cin >> n >> rnd;
  for(i=0;i<n;i++){
    cin >> minute;
    arr[i] = minute;
    if (minute < mn){
      mn = minute;
    }
  }
  long long finish;
  long long num = 0;
  finish = mn*rnd;
  for(i=0;i<n;i++){
      if(arr[i]*rnd - finish - arr[i] < 0){
          num += 1;
          }
      }
  cout << num;
  return 0;
}