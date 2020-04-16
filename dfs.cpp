#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
int h,w;
char m[500][500];
bool reach[500][500];
bool frag = false;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void search(int x,int y){
    if(x<0 || w <= x || y < 0 || h <= y || m[x][y] == '#'){
        return;
    }

    if(reach[x][y] == true) return;
    if(m[x][y] == 'g'){
        frag = true;
    }
    reach[x][y] = true;   

    rep(i,0,4) search(x+dx[i], y+dy[i]);
}

int main(){
    cin >> h >> w; cin.ignore();
    int a,b;
    rep(i,0,h)
    {
        string s; getline(cin,s);
        rep(k,0,w)
        {
            m[k][i] = s[k];
            if(m[k][i] == 's'){
                a = k; b = i;
            }
        }
    }

    search(a,b);

    if(frag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}