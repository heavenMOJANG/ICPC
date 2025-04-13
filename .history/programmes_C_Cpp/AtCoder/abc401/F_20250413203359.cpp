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
    sort(d.begin(), d.end());
    return d;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n1; cin >> n1;
    vector a = solve(n1);
    int n2; cin >> n2;
    vector b = solve(n2);
    int d = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));
    cout << d << "\n";
    for (int i{}; i < n1; ++ i) cout << a[i] << " \n"[i == n1 - 1];
    for (int i{}; i < n2; ++ i) cout << b[i] << " \n"[i == n2 - 1];
    int tot{};
    stack<int> s;
    for (int i{}; i < n2; ++ i) s.push(b[i]);
    int ans{};
    for (int i{}; i < n1; ++ i) {
        while (!s.empty() && a[i] + s.top() + 1 > d) tot += s.top(), s.pop();
        ans += s.size() * d + tot + (a[i] + 1) * (n2 - s.size());
    }
    cout << ans << "\n";
    return 0;
}