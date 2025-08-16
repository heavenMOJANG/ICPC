#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, l; cin >> n >> m >> l;
    vector<int> a(n); for (auto && x : a) cin >> x;
    vector cnt(l, vector<int> (m, 0));
    for (int i{}; i < n; ++ i) cnt[i % l][a[i] % m] ++;
    vector<int> dp(m, INF), ndp(m);
    dp[0] = 0;
    for (int i{}; i < l; ++ i) {
        int res{}, sum{};
        for (int r{}; r < m; ++ r) res += cnt[i][r], sum += r * cnt[i][r];
        vector<int> pre(m); pre[0] = cnt[i][0];
        for (int r = 1; r < m; ++ r) pre[r] = pre[r - 1] + cnt[i][r];
        fill(ndp.begin(), ndp.end(), INF);
        for (int s{}; s < m; ++ s) {
            if (dp[s] == INF) continue;
            for (int r{}; r < m; ++ r) {
                int w = r * res - sum + (res - pre[r]) * m;
                ndp[(s + r) % m] = min(ndp[(s + r) % m], dp[s] + w);
            }
        }
        dp.swap(ndp);
    }
    cout << dp[0] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}