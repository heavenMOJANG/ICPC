#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int v = 2; v <= n; ++ v) {
        int u; cin >> u;
        g[u].emplace_back(v);

    }
    vector<int> dp(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int fa) {

    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}