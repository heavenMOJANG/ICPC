#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), sum(n, 0);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    unordered_set<int> ans;
    int xsum{};
    function<void(int, int)> dfs = [&](int x, int ly) {
        for (int i = 0; i <= ly; ++ i) {
            xsum ^= sum[i];
            sum[i] += a[x];
            xsum ^= sum[i];
            if (x == n - 1) ans.insert(xsum);
            else if (i < ly) dfs(x + 1, ly);
            else dfs(x + 1, ly + 1);
            xsum ^= sum[i];
            sum[i] -= a[x];
            xsum ^= sum[i];
        }
    };
    dfs(0, 0);
    cout << ans.size() << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}