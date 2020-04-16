#include <bits/stdc++.h>
using namespace std;

int h,w;
char m[500][500];
bool reach[500][500];
bool frag = false;

void search(int x,int y){
    if(x<0 || w <= x || y < 0 || h <= y || m[x][y] == '#'){
        return;
    }

    if(reach[x][y] == true) return;
    if(m[x][y] == 'g'){
        frag = true;
    }
    reach[x][y] = true;   

    search(x+1,y);
    search(x-1,y);
    search(x,y+1);
    search(x,y-1);
}

int main(){
    cin >> h >> w;cin.ignore();
    int a,b;
    for(int i = 0; i<h;i++){
        string s;
        getline(cin,s);
        for(int k = 0; k<w;k++){
            m[k][i] = s[k];
           if(m[k][i] == 's'){
                a = k;b = i;
            }
        }
    }
    search(a,b);
    if(frag == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}