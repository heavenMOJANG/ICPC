#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string g[n];
    vector<int> r(n, 0), c(n, 0);
    for (int i = 0; i < n; ++ i) {
        cin >> g[i];
        for (int j = 0; j < m; ++ j) if (g[i][j] == '1') r[i] ^= 1, c[j] ^= 1;
    }
    int ans{};/*
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) {
            if (r[i] && c[j]) {
                ans ++;
                r[i] ^= 1;
                c[j] ^= 1;
            }
        }*/
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}