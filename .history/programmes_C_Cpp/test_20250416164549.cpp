#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
struct Fenwick {
    vector<int> t;
    int n;
    Fenwick(int _) : t(_ + 1, 0), n(_) {}
    int lowbit(int x) { return x & -x; }
    void update(int x, int d) { while (x <= n) t[x] += d, x += lowbit(x); }
    int query(int x) {
        int res{};
        while (x) res += t[x], x -= lowbit(x);
        return res;
    }
};
void solve() {
    int n, r; cin >> n >> r;
    vector<int> g[n + 1];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> siz(n + 1, 1);
    Fenwick ft(n);
    int fac = 1, s1{}, s2{};
    function<void(int, int)> dfs = [&](int u, int fa) {
        ft.update(u, 1);
        s1 = (s1 + ft.query(n) - ft.query(u)) % MOD;
        int cnt{};
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
            cnt ++;
        }
        for (int i = 1; i <= cnt; ++ i) fac = fac * i % MOD;
        s2 = (s2 + n - ft.query(n) - siz[u] + 1) % MOD;
        ft.update(u, -1);
    };
    dfs(r, -1);
    int ans = (s1 * fac + s2 * fac % MOD * (MOD + 1) / 4) % MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}