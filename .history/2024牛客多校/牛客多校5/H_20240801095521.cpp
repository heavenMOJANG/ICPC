#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
int n, m, h[40], ans;
vector<int> g[40];
void dfs(int u, const int & f = 9, int len = 1) {
    
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int u, const int & f, int len) {
        ans = max(ans, len);
        for (auto v : g[u])
            if ((f >> v) & 1 == 0 && (h[v] & f) == 0) dfs (v, f | (1ll << u), len + 1);
    };
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    vector<int> g[n], h(n, 0);
    for (int i = 0, u, v; i < m; ++ i) {
        cin >> u >> v;
        u --, v --;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        h[u] |= 1ll << v;
        h[v] |= 1ll << u;
    }
    for (int i = 0; i < n; ++ i) dfs(i);
    cout << ans << "\n";
    return 0;
}