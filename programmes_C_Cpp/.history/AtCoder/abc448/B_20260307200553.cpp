#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> c(m);
    for (auto && x : c) cin >> x;
    int ans{};
    vector<int> cnt(m, 0);
    for (int i{}; i < n; ++ i) {
        int a, b; cin >> a >> b;
        cnt[a] += b;
    }
    for (int i{}; i < m; ++ i) ans += min(cnt[i], c[i]);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}