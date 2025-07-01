#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> c(n);
    for (int i{}; i < n; ++ i) cin >> c[i];
    vector a(n, vector<int> (m, 0));
    for (int i{}; i < m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            int x; cin >> x;
            a[x - 1][i] = 1;
        }
    }
    int minn = LLONG_MAX;
    vector<int> cnt(m, 0);
    int tot{};
    function<void(int)> dfs = [&](int x) {
        if (x == n) {
            int ok = 1;
            for (int i{}; i < m; ++ i) if (cnt[i] < 2) { ok = 0; break; }
            if (ok) minn = min(minn, tot);
            return;
        }
        for (int i{}; i < 3; ++ i) {
            tot += c[x] * i;
            for (int j{}; j < m; ++ j) cnt[j] += a[x][j] * i;
            dfs(x + 1);
            for (int j{}; j < m; ++ j) cnt[j] -= a[x][j] * i;
            tot -= c[x] * i;
        }
    };
    dfs(0);
    cout << minn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}