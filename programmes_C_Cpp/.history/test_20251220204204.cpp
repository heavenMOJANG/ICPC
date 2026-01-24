#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int INF = 0x7fffffff;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n + 1), y(n + 1);
    vector<vector<pair<int,int>>> g(n + 1);

    // 建图：x -> i，边权 y
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        g[x[i]].emplace_back(y[i], i);
    }

    // 按 (y, i) 排序，保证字典序 + 下标顺序
    for (int i = 0; i <= n; ++i) {
        sort(g[i].begin(), g[i].end(), [](auto &a, auto &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
    }

    // dfn：记录 DFS 访问顺序
    vector<int> dfn(n + 1, -1);
    int timer = 0;

    function<void(int)> dfs = [&](int u) {
        dfn[u] = timer++;
        for (auto &[_, v] : g[u]) {
            dfs(v);
        }
    };

    // 从 0（空序列）开始 DFS
    dfs(0);

    // 按 DFS 序排序 1..n
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);

    sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (dfn[a] != dfn[b]) return dfn[a] < dfn[b];
        return a < b;
    });

    for (int i = 0; i < n; ++i) {
        cout << ord[i] << " \n"[i + 1 == n];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}
