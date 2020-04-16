#include<iostream>
#include <vector>
using namespace std;

vector<int> a = { 1,5,16,74,333,337,1111};

//index が条件を満たすかどうか
bool isOK(int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

//二分探索のテンプレ
int binary_search(int key){
    int ng = -1;
    int ok = (int)a.size();
    
    // ok と　ng のどちらが大きいかわからないことに考慮
    while(abs(ok - ng) > 1)
    {
        int mid = (ok + ng)/2;
        
        if(isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cout << binary_search(51) << endl;
}