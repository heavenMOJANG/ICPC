#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = LLONG_MIN;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i] >> v[i];
    vector dpp(n + 10, vector<int>(m + 10, INF));
    dpp[0][0] = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j{}; j <= m; ++ j) {
            dpp[i][j] = dpp[i - 1][j];
            if (j >= p[i] && dpp[i - 1][j - p[i]] != INF) dpp[i][j] = max(dpp[i][j], dpp[i - 1][j - p[i]] + v[i]);
        }
    int maxn{};
    for (int j{}; j <= m; ++ j) maxn = max(maxn, dpp[n][j]);
    vector dps(n + 10, vector<int>(m + 10, INF));
    dps[n + 1][0] = 0;
    for (int i = n; i; -- i)
        for (int j{}; j <= m; ++ j) {
            dps[i][j] = dps[i + 1][j];
            if (j >= p[i] && dps[i + 1][j - p[i]] != INF) dps[i][j] = max(dps[i][j], dps[i + 1][j - p[i]] + v[i]);
        }
    vector pre(n + 10, vector<int>(m + 10, INF));
    for (int i = 1; i <= n + 1; ++ i) {
        int res = INF;
        for (int j{}; j <= m; ++ j) pre[i][j] = res = max(res, dps[i][j]);
    }
    string ans(n, 'C');
    for (int i = 1; i <= n; ++ i) {
        int f1{}, f0{};
        for (int j{}; j <= m && !f1; ++ j) {
            if (dpp[i - 1][j] == INF) continue;
            int d = m - j - p[i];
            if (d < 0) continue;
            int tot = dpp[i - 1][j] + v[i] + pre[i + 1][d];
            if (tot == maxn) f1 = 1;
        }
        for (int j{}; j <= m && !f0; ++ j) {
            if (dpp[i - 1][j] == INF) continue;
            int d = m - j;
            int tot = dpp[i - 1][j] + pre[i + 1][d];
            if (tot == maxn) f0 = 1;
        }
        if (f1 && !f0) ans[i - 1] = 'A';
        else if (f1 && f0) ans[i - 1] = 'B';
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}