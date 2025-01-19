#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    string s; cin >> s;
    s = " " + s;
    vector<int> a(2, 0);
    int ans{}, res{};
    function<void(int, int)> dfs = [&](int u, int f) {
        int sum{};
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(v, u);
            sum ++;
        }
        if (!sum) {
            if (s[u] == '?') ans ++;
            else if (s[u] == '0') a[0] ++;
            else a[1] ++;
        } else {
            if (u != 1 && s[u] == '?') res ++;
        }
    };
    dfs(1, 0);
    if (s[1] == '?') {
        int maxn = 0;
        if (a[1] < a[0]) swap(a[1], a[0]);
        maxn = max(maxn, a[1] + ans / 2);
        maxn = max(maxn, min(a[0] + 1, a[1]) + ans / 2);
        if (res & 1) maxn = max(maxn, a[1] + a[0] + ans - maxn);
        cout << maxn << "\n";
    } else {
        if (s[1] == '1') cout << a[0] + (ans + 1) / 2 << "\n";
        else cout << a[1] + (ans + 1) / 2 << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}