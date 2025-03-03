#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
int n, m, rt, pos[N], dfn[N << 1], dep[N], idx, dp[30][N << 1], rev[30][N << 1], lg[N << 1];
vector<int> g[N];
void dfs(int u, int d) {
    dfn[++ idx] = u;
    dep[idx] = d;
    pos[u] = idx;
    for (auto v : g[u])
        if (!pos[v]) {
            dfs(v, d + 1);
            dfn[++ idx] = u;
            dep[idx] = d;
        }
}
void init() {
    for (int i = 2; i <= idx + 1; ++ i) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= idx; ++ i) dp[0][i] = dep[i], rev[0][i] = dfn[i];
    for (int i = 1; i <= lg[idx]; ++ i)
        for (int j = 1; j + (1ll << i) - 1 <= idx; ++ j)
            if (dp[i - 1][j] < dp[i - 1][j + (1ll << i - 1)]) dp[i][j] = dp[i - 1][j], rev[i][j] = rev[i - 1][j];
            else dp[i][j] = dp[i - 1][j + (1ll << i - 1)], rev[i][j] = rev[i - 1][j + (1ll << i - 1)];
}
int query(int l, int r) {
    int t = lg[r - l + 1];
    return dp[t][l] < dp[t][r - (1ll << t) + 1] ? rev[t][l] : rev[t][r - (1ll << t) + 1];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> rt;
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(rt, 1);
    init();
    while (m --) {
        int u, v; cin >> u >> v;
        cout << query(u, v) << "\n";
    }
    return 0;
}