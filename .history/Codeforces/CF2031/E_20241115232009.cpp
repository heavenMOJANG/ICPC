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
    function<void(int)> dfs = [&](int u) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto v : g[u]) {
            dfs(v);
            pq.push(dp[v]);
        }
        if (pq.empty()) dp[u] = 1;
        else if (pq.size() == 1) dp[u] = pq.top() + 1;
        else {
            while (pq.size() >= 2) {
                int a = pq.top(); pq.pop();
                int b = pq.top(); pq.pop();
                pq.push(max(a, b) + 1);
            }
            dp[u] = pq.top();
        }
    };
    dfs(1);
    cout << dp[1] - 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}