#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> c[i];
    vector<int>g[n + 1];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> siz(n + 1), big(n + 1), L(n + 1), R(n + 1), Node(n + 1);
    int dfn = 0, tot = 0;
    vector<int> cnt(n + 1, 0), ans(n + 1);
    function<void(int)> add = [&](int u){
        if (!cnt[c[u]]) ++ tot;
        cnt[c[u]] ++;
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}