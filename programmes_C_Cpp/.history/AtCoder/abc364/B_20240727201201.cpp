#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    int si, sj; cin >> si >> sj;
    si --, sj --;
    vector<vector<char>>g(n, vector<char>(m));
    for(int i = 0; i < n; ++ i)
        for(int j = 0;j < m; ++ j) cin >> g[i][j];
    string s; cin >> s;
    for (auto c : s) {
        int tx = si, ty = sj;
        switch (c) {
            case 'L' : {tx --; break;}
            case 'R' : {tx ++; break;}
            case 'U' : {ty ++; break;}
            case 'D' : {ty --; break;}
        }
        if (tx < 0 || tx >= n || ty < 0 || ty >= m || g[tx][ty] == '#') continue;
        si = tx, sj = ty;
    }
    cout << si + 1 << " " << sj + 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}