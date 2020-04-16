#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
typedef pair<int,int> P;
typedef long long ll;
ll n,m,k,ans;
string s;

int main(){
  const long long INF = (1LL<<32);
  int v,e; cin >> v >> e;
  int s,t,d;
  long long g[v][v];
  bool frag = true;
  rep(i,v) rep(j,v) g[i][j] = ( (i == j)? 0 : INF );
  rep(i,e){
    cin >> s >> t >> d; g[s][t] = d;
  }
  rep(k,v) rep(i,v) {
    if(g[i][k] == INF) continue;
    rep(j,v){
      if(g[k][j] == INF) continue;
      g[i][j] = min( g[i][j], g[i][k]+g[k][j] );
    }
  }
  rep(i,v) if( g[i][i] < 0 ) frag = false;
  if(frag){
    rep(i,v) {
      rep(j,v){
        if(g[i][j] == INF) cout << "INF";
        else cout << g[i][j];
        if(j < v-1) cout << " ";
      }
      cout << "\n";
    }
  }else cout <<"NEGATIVE CYCLE\n";
  }
}