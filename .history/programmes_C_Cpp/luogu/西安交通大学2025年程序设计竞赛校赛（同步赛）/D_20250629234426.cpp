#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector g(n + 2, vector<char>(m + 2, 'W'));
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> g[i][j];
    {
        int ok = 1;
        vector a = g;
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j) if (a[i][j] == 'B') a[n - i + 1][j] = 'B';
        for (int i = 1; i <= n; ++ i) 
    }
    {

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}