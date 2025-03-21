#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> post(n), in(n);
    for (auto && x : post) cin >> x;
    for (auto && x : in) cin >> x;
    int p = 1;
    function<void(int, int, int, int)> dfs = [&](int rt, int p, int pl, int pr) {
        if (x > n) return;
        dfs(x << 1);
        dfs(x << 1 | 1);
        ans[x] = post[p ++];
    };
    dfs(1);
    for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}