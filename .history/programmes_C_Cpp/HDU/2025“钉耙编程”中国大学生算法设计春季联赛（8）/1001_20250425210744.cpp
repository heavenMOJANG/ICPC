#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector g(n, vector<int> (m));
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) cin >> g[i][j];
    vector<int> cur(k + 1, n);
    int cnt{}, ans{};
    for (int j{}; j < m; ++ j) {
        vector<int> tmp(k + 1, n);
        for (int i{}; i < n; ++ i)
            if (tmp[g[i][j]] == n) tmp[g[i][j]] = i;
        for (int c = 1; c <= k; ++ c)
            if (tmp[c] < n) {
                if (cur[c] == n) cur[c] = tmp[c], cnt ++;
                else cur[c] = min(cur[c], tmp[c]);
            }
        if (cnt == k) ans += n - *max_element(cur.begin() + 1, cur.end());
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}