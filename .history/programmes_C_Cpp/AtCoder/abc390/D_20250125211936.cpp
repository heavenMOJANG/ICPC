#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), sum(n);
    multiset<int> s[n];
    set<int> ans;
    function<void(int)> dfs(int x, int ly) {
        if (x == n) {
            int res{};
            for (int i = 0; i < ly; ++ i) res ^= sum[i];
            ans.insert(res);
        }
        for (int i = 0; i < ly; ++ i) {
            s[i].insert(a[x]);
            sum[i] += a[x];
            if (i == ly - 1) dfs(x + 1, ly + 1);
            else dfs(x + 1, ly);
            s[i].erase(a[x]);
            sum[i] -= a[x];
        }
    };
    s[0].insert(a[0]); sum[0] += a[0];
    dfs(1, 2);
    cout << ans.size() << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}