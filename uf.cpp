#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
typedef pair<int,int> P;

class UnionFind {
  public:
    vector<int> rank, p;
    UnionFind(){}
    UnionFind(int size){
      rank.resize(size, 0); p.resize(size, 0);
      rep(i,size) makeSet(i);
    }
    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
    }
    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }
    void unite(int x, int y){
      link(findSet(x), findSet(y));
    }
    void link(int x, int y){
      if(rank[x] > rank[y]) p[y] = x;
      else{
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++; //同じランクはxORyに統一して併合
      }
    }
    int findSet(int x){
      if(x != p[x]) p[x] = findSet(p[x]);
      return p[x];
    }
};
int main(){
  int n,a,b,q,t;
  cin >> n >> q;
  UnionFind uf = UnionFind(n);
  vector<int> ans;
  rep(i,q){
    cin >> t >> a >> b;
    if(t == 0) uf.unite(a, b);
    else if(t == 1){
      if(uf.same(a,b)) ans.push_back(1);
      else ans.push_back(0);
    }
  }
  rep(i,ans.size()) cout << ans[i] << "\n";
}