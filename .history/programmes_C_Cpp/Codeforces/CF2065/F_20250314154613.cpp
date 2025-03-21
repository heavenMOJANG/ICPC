#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    vector<int> g[n];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    string s(n, '0');
    for (int i = 0; i < n; ++ i) {
        set<int> se;
        se.insert(a[i]);
        for (auto v : g[i]) {
            if (se.count(a[v])) s[a[v] - 1] = '1';
            se.insert(a[v]);
        }
    }
    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}