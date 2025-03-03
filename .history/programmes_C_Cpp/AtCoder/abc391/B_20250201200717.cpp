#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> f(n, vector<char> (n)), g(m, vector<char>(m));
    for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) cin >> f[i][j];
    for (int i = 0; i < m; ++ i) for (int j = 0; j < m; ++ j) cin >> g[i][j];
    int ans{};
    for (int i = 0; i + m - 1 < n; ++ i) for (int j = 0; j + m - 1 < n; ++ j) {
        int flag = 1;
        for (int a = 0; a < m; ++ a) for (int b = 0; b < m; ++ b) if (f[i + a][j + b] != g[a][b]) flag = 0;
        if (flag) { cout << i << " " << j << "\n"; return; }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}