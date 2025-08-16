#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
constexpr int N = 2e5 + 10;
int fac[N];
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> clr(n + 1, -1);
    queue<int> q;
    int ok = 1;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}