#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
vector<int> g[N];
int n, siz[N], ans[N], preS[N], preC[N];
ll get(ll x) { return x * (x - 1) / 2; }
void dfs(int u, int fa) {
    
}
void dfs1(int u, int fa) {
    int len = g[u].size();
    for (int i = 1; i <= len; ++ i)
        if (g[u][i - 1] == fa) {
            preS[i] = preS[i - 1] + siz[1] - siz[u];
            preC[i] = preC[i - 1] + get(siz[1] - siz[u]);
        } else {
            preS[i] = preS[i - 1] + siz[g[u][i - 1]];
            preC[i] = preC[i - 1] + get(siz[g[u][i - 1]]);
        }
    for (int i = 1; i <= len; ++ i) {
        ans[u] += (preS[i] - preS[i - 1]) * (get(preS[i - 1] + preS[len] - preS[i]) - (preC[i - 1] + preC[len] - preC[i]));
        ans[u] += (preS[i] - preS[i - 1]) * (preS[i - 1] + preS[len] - preS[i]);
    }
    ans[u] += siz[1] - 1;
    ans[u] += get(preS[len]) - preC[len];
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs1(v, u);
    }
}
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> siz(n + 1, 1);
    function<void(int, int)> dfs0 = [&](int u, int fa) {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
    };
    dfs0(1, -1);
    dfs1(1, -1);
    for (int i = 1; i <= n; ++ i) cout << ans[i] + siz[1] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}