#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> t(n + 1, 0), flag(n + 1, 0);
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i <= n; ++ i) {
        int p, tt; cin >> p >> tt;
        if (p == 1) {
            for (int j = 0, x, a; j < tt; ++ j) {
                cin >> x >> a;
                g[i].emplace_back(a, x);
            }
        } else t[i] = tt;
    }
    int flag = 0;
    function<void(int)> dfs = [&](int u) {
        if (u == k) {
            for(auto [v, w] : g[u]) {
                dfs(v);
                if (!flag[u]) t[u] += t[v] * w;
            }
        } else {
            for (auto [v, w] : g[u]) {
                dfs(v);
                t[u] += t[v] * w;
                if (flag[v]) flag[u] = 1;
                if (t[u] > 1e9) flag[u] = 1;
            }
        }
        
    };
    dfs(k);
    int maxn = 0;
    int cnt = 0;
    for (auto [v, w] : g[k]) maxn = max(maxn, t[v] * w);
    if (t[k] - maxn > 1e9) cout << "Impossible\n";
    else cout << t[k] - maxn << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}