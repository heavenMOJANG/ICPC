#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
vector<int> solve(int n) {
    vector<int> g[n];
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v; u --, v --;
        g[u].emplace_back(u);
        g[v].emplace_back(v);
    }
    vector dp(3, vector<int>(n, 0));
    vector<int> id(n, 0);
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs1(v, u);
            if (dp[0][u] < dp[0][v] + 1) {
                dp[0][u] = dp[0][v] + 1;
                id[u] = v;
            }
        }
        for (auto v : g[u]) {
            if (v == fa || v == id[u]) continue;
            dp[1][u] = max(dp[1][u], dp[0][v] + 1);
        }
    };
    function<void(int, int)> dfs2 = [&] (int u, int fa) {
        for (auto v : g[u]) {
            if (v == fa) continue;
            if (v == id[u]) dp[2][v] = max(dp[2][u], dp[1][u]) + 1;
            else dp[2][v] = max(dp[2][u], dp[0][u]) + 1;
            dfs2(v, u);
        }
    };
    dfs1(0, -1);
    dfs2(0, -1);
    vector<int> d(n);
    for (int i{}; i < n; ++ i) d[i] = max(dp[0][i], dp[2][i]);
    return d;
}
vector<int> solve() {
    int n1; cin >> n1;
    vector<vector<int>> g1(n1);
    for (int i = 1; i < n1; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g1[u].emplace_back(v);
        g1[v].emplace_back(u);
    }
    vector<int> dep1
    int n2; cin >> n2;
    vector<vector<int>> g2(n2);
    for (int i = 1; i < n2; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g2[u].emplace_back(v);
        g2[v].emplace_back(u);
    }
    vector<int> dep1(n1, 0), dep2(n2, 0);
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (auto v : g2[u]) {
            if (v == fa) continue;
            dep2[v] = dep2[u] + 1;
            dfs2(v, u);
        }
    };

    int maxn{}, u1{}, v1{}, u2{}, v2{};

    dfs(g1, dep1u, 0, -1);
    for (int i{}; i < n1; ++ i) if (dep1u[i] > maxn) maxn = dep1u[i], u1 = i;
    fill(dep1u.begin(), dep1u.end(), 0);
    dfs(g1, dep1u, u1, -1);
    maxn = 0;
    for (int i{}; i < n1; ++ i) if (dep1u[i] > maxn) maxn = dep1u[i], v1 = i;
    int d1 = maxn;
    dfs(g1, dep1v, v1, -1);
    vector<int> a(n1);
    for (int i{}; i < n1; ++ i) a[i] = (max(dep1u[i], dep1v[i]));

    maxn = 0;
    dfs(g2, dep2u, 0, -1);
    for (int i{}; i < n2; ++ i) if (dep2u[i] > maxn) maxn = dep2u[i], u2 = i;
    fill(dep2u.begin(), dep2u.end(), 0);
    dfs(g2, dep2u, u2, -1);
    maxn = 0;
    for (int i{}; i < n2; ++ i) if (dep2u[i] > maxn) maxn = dep2u[i], v2 = i;
    int d2 = maxn;
    dfs(g2, dep2v, v2, -1);
    vector<int> b(n2);
    for (int i{}; i < n2; ++ i) b[i] = (max(dep2u[i], dep2v[i]));
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    int tot{};
    stack<int> s;
    for (int i{}; i < n2; ++ i) s.push(b[i]);
    int ans{};
    for (int i{}; i < n1; ++ i) {
        while (!s.empty() && a[i] + s.top() + 1 > maxn) tot += s.top(), s.pop();
        ans += s.size() * maxn + tot + (a[i] + 1) * (n2 - s.size());
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n1; cin >> n1;
    return 0;
}