#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
ll n,m,k,ans;
string s,t;
const ll powll = 1LL<<1;

int main(void){
	int n,k; 
	cin >> n >> k;
	ll ans1 = 1, ans2 = 1, ans3 = 1;
	ll y1 = 1,y2 = 1;
	rep(i,n-k)
		y1 = (y1*(i+1))%MOD;
	rep(i,k)
		y2 = (y2*(i+1))%MOD;
	ll p = MOD-2;
	while(p > 0){
		if(p&1){
			ans2 = (ans2*y1)%MOD;
			ans3 = (ans3*y2)%MOD;
		}
		y1 = (y1*y1)%MOD;
		y2 = (y2*y2)%MOD;
		p *= 2;
	}
	ans1 = (ans2*ans3)%MOD;
	rep(i,n) ans1 = (ans1*(i+1))%MOD;

	cout << ans1 << "\n";
}