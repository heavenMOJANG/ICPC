#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> x(n + 1), y(n + 1);
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i <= n; ++ i) {
        cin >> x[i] >> y[i];
        g[i].emplace_back(y[i], i);
    }
    for (int i{}; i <= n; ++ i) sort(g[i].begin(), g[i].end(), [](const auto &a, const auto &b) {
        return a.first != b.first ? a.first < b.first : a.second < b.second;
    });
    vector<int> rk(n + 1);
    int dfn{};
    function<void(int)> dfs = [&](int u) {
        rk[u] = dfn ++;
        for (auto [_, v] : g[u]) dfs(v);
    };
    dfs(0);
    vector<int> num(n);
    iota(num.begin(), num.end(), 1);
    sort(num.begin(), num.end(), [&](int a, int b) {
        return rk[a] != rk[b] ? rk[a] < rk[b] : a < b;
    });
    for (int i{}; i < n; ++ i) cout << num[i] << " \n"[i + 1 == n];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}