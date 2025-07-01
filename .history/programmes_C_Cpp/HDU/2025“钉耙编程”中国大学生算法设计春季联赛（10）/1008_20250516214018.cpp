#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector a(n, vector<int>(m));
    vector<pair<int, int>> mx(n);
    for (int i{}; i < n; ++ i) {
        for (int j{}; j < m; ++ j) {
            cin >> a[i][j];
            pq[i].push({a[i][j], j});
        }
    }
    if (m == 1) {
        int ans{};
        for (int i{}; i < n; ++ i) ans += a[i][0];
        cout << ans << "\n";
        return;
    }
    int maxn{};
    for (int k{}; k < m; ++ k) {
        vector<int> b(n);
        for (int i{}; i < n; ++ i) {
            
        }
        vector<int> d(n);
        for (int i{}; i < n; ++ i) d[i] = a[i][k] - b[i];
        sort(d.begin(), d.end(), greater<int>());
        int res = accumulate(b.begin(), b.end(), 0);
        for (int i{}; i < n / 2 + 1; ++ i) res += d[i];
        maxn = max(maxn, res);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}