#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int, vector<int>> a(n, vector<int>(m));
    map<vector<int>, int> mpRow, mpCol;
    for (int i = 0; i < n; ++ i) {
        vector<int> t(m);
        for (int j = 0; j < m; ++ j) cin >> a[i][j], t[j] = a[i][j];
        sort(t.begin(), t.end());
        mpRow[t] ++;
    }
    for (int j = 0; j < m; ++ j) {
        vector<int> t(n);
        for (int i = 0;i < n; ++ i) t[i] = a[i][j];

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}