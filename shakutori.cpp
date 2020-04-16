#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
typedef pair<int,int> P;

int main(){
  int n;cin >> n;
  long long k;cin >> k;
  long long sum = 0;
  int a[n]; rep(i,n) cin >> a[i];
  long long ans  = 0;
  int r = 0;
  rep(l,n){
    while(sum<k){
      if(r == n) break;
      else {
        sum += a[r];
        r++;
      }
    }
    if(sum < k) break;
    ans += n-+1;
    sum-=a[l];
  }
  cout << ans << endl;
}