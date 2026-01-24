#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= n; ++ i) {
        int u, w; cin >> u >> w;
        g[u].emplace_back(w, i);
    }
    vector<int> ans;
    function<void(const vector<int>&)> dfs = [&](const vector<int>& cur) {
        for (int u : cur) if (u != 0) ans.push_back(u);
        vector<pair<int, int>> nxt;
        for (int u : cur) for (auto& edge : g[u]) nxt.emplace_back(edge);
        if (nxt.empty()) return;
        sort(nxt.begin(), nxt.end());
        int m = nxt.size();
        for (int i{}; i < m; ) {
            int j = i;
            vector<int> res;
            int cur_w = nxt[i].first;
            while (j < m && nxt[j].first == cur_w) res.push_back(nxt[j ++].second);
            dfs(res);
            i = j;
        }
    };
    dfs({0});
    for (int i{}; i < n; ++ i) cout << ans[i] << " \n"[i + 1 == n];
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; // cin >> _; 
    while(_ --) solve();
    return 0;
}