#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
 
#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
typedef pair<int,int> P;
 
int main(){
  long long n,m,p; cin >> n >> m >> p;
  long long ans = 1;
  long long i = n;
  while(p > 0){
    if( p & 1 ) ans = (ans*i)%m;
    i = (i*i)%m;
    p >>= 1;
  }
  cout << ans << "\n";
}