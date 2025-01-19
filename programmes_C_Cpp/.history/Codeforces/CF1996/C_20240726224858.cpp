#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vector<vector<int>> preA(n + 1, vector<int>(26, 0)), preB(n + 1, vector<int>(26, 0));
    a = " " + a; b = " " + b;
    for (int i = 1; i <= n; ++ i) {
        int c = a[i] - 'a';
        preA[i][c] ++;
        for (int j = 0; j < 26; ++ j)
            preA[i][j] += preA[i - 1][j];
    }
    for (int i = 1; i <= n; ++ i) {
        int c = b[i] - 'a';
        preB
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}