#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> g[n + 1];
    for (int v = 2, u; v <= n; ++ v) {
        cin >> u;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int f) {
        int minn = inf;
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(v, u);
            minn = min(minn, a[v]);
        }
        if (minn == inf) return;
        if (u == 1) {
            a[u] += minn;
            return;
        }
        if (a[u] < minn) {a[u] = minn; return;} 
        else {a[u] = (a[u] + minn) / 2; return;}
    };
    dfs(1, -1);
    cout << a[1] << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}