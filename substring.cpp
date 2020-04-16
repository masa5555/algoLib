\*
●部分文字列とは
ある文字列sに対して、
    ・sを構成する文字を0文字以上取り除き
    ・残った文字をもとの順番で並べる

・ポイント
    同じ文字列を生成する選び方のうち、
    選ぶindexの辞書順が最小になるものだけを考えて、
    それ以外は捨てる

・定義
    各文字について「選ぶ」か「選ばない」か二択を繰り返す

dp[i] :文字列ｓにおいて、i-1番目の文字は必ず使うものとして、
    0番目からi-1番目までの部分から得られる文字列の個数

    文字列"nyanpasu"について
    dp[0] = 1: ""
    dp[1] = 1: "n"
    dp[2] = 2: "y" "ny"
    ...
    dp[n] = 1; "nyanpasu"

遷移
    各文字cについて、next[i][c] < nならば、　
    dp[next[i][c] + 1] += dp[i]
    ※next[i][c]: sのi文字目以降で最初に文字ｃが登場するindex
    
*\


#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

// mod 1000000007 の世界で a += b する関数
void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    // 入力
    string S; cin >> S;
    int n = (int)S.size();

    // 前処理配列
    vector<vector<int> > next = calcNext(S);

    // DP
    vector<long long> dp(n+1, 0);
    dp[0] = 1; // 初期化、空文字列 "" に対応
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (next[i][j] >= n) continue; // 次の文字 j がもうない場合はスルー
            add(dp[next[i][j] + 1], dp[i]);
        }
    }

    // 集計
    long long res = 0;
    for (int i = 0; i <= n; ++i) add(res, dp[i]);

    cout << res << endl;
}