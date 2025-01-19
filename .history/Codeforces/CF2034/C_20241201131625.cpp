#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string g[n + 1];
    for (int i = 1; i <= n; ++ i) cin >> g[i], g[i] = " " + g[i];
    vector<pair<int, int>> acc[n + 2][m + 2];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            switch (g[i][j]) {
                case 'U':acc[i - 1][j].emplace_back(i, j); break;
                case 'D':acc[i + 1][j].emplace_back(i, j); break;
                case 'L':acc[i][j - 1].emplace_back(i, j); break;
                case 'R':acc[i][j + 1].emplace_back(i, j); break;
                default: continue;

            }
            if (g[i][j] == 'U') 
            if (g)
        }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}