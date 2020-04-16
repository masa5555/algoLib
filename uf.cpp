#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define rep(i,a,n) for(int i=a;i<n;i++)

// Test Passed

struct UnionFind 
{
    vector<int> rank, par;

    UnionFind(int n){
    	rank.resize(n, 0); 
		par.resize(n, 0);
    	rep(i,0,n) makeSet(i);
    }

    void makeSet(int i){
      	par[i] = i;
      	rank[i] = 0;
    }

	int find(int x){
      	if(x == par[x])
		  	return x;
		else 
			return par[x] = find(par[x]);
    }

    bool same(int x, int y){
      	return find(x) == find(y);
    }

    void link(int x, int y){
      	if(rank[x] > rank[y]) par[y] = x;
      	else{
        	par[x] = y;
       		if(rank[x] == rank[y]) rank[y]++; 
			//同じランクはxORyに統一して併合
      	}
    }

	void unite(int x, int y){
      	link(find(x), find(y));
    }
};

int main(){
	int n,q,t,a,b;
	cin >> n >> q;
	UnionFind uf = UnionFind(n);
	vector<int> ans;
	rep(i,0,q)
	{
		cin >> t >> a >> b;
		if(t == 0) uf.unite(a, b);
		else if(t == 1){
			if(uf.same(a,b)) ans.push_back(1);
			else ans.push_back(0);
		}
	}
	rep(i,0,ans.size()){
		if(ans[i]) cout << "Yes\n";
		else cout << "No\n";
	}
}