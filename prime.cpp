#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> p;

  for(int i = 2; i<=200000; i++){
    bool isPrime = true;
    int j = 0;
    while(j < p.size() && p[j]*p[j] <= i){
      if(i % p[j] == 0) isPrime = false;
      j++;
    }
    if( isPrime ) p.push_back(i);
  }
  
  rep(i,p.size()){
    if(p[i] >= n){
      cout << p[i] <<  "\n";
      break;
    }
  }
}