#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
const long long INF = MOD*MOD;
typedef pair<int,int> P;
typedef long long ll;

int w,h;
bool isV[501][501];
int m[501][501];
char s[501][501];
int dx[4] = {1,0,-1,0};int dy[4] = {0,1,0,-1};

int bfs(){
  int distanse = 0;
  queue<P> que;
  // while having que
  while( que.size() ){ 
    P p = que.front();que.pop();
    rep(i, 4){
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if(nx >= 0 and nx < w and ny >= 0 and ny < h and s[nx][ny] == '.' and isV[nx][ny] == false){
        isV[nx][ny] = true;
        que.push(P(nx,ny));
        m[nx][ny] = m[p.first][p.second] + 1;
        ans = max(ans,m[nx][ny]);
      }
    }
  }
  return 
}
 
int main(void){
  cin >> h >> w;
  cin.ignore();
  rep(i,h){
    string st; getline(cin,st);
    rep(j,w) s[j][i] = st[j];
  }
  
  rep(k,h) rep(l,w){
    if(s[l][k] == '.'){
      rep(i,w) rep(j,h) {m[i][j] = MOD;isV[i][j] = false;}
      isV[l][k] = true;
      m[l][k] = 0;
      que.push({l,k});
      bfs();
    }
  }

  cout << ans << "\n";
}