#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    for (int i : views::iota(0, N - 1)) {
        int u, v; cin >> u >> v, u -- , v --;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    auto bfs = [&](int s, vector<int>& f) {
        vector<int> dis(N, -1);
        queue<int> q; q.push(s);
        dis[s] = 0;
        int end{s};
        while (!q.empty()) {
            int u{q.front()}; q.pop();
            if (dis[u] > dis[end]) end = u;
            for (int v : G[u]) {
                if (dis[v] != -1) continue;
                dis[v] = dis[u] + 1;
                f[v] = u;
                q.emplace(v);
            }
        }
        return end;
    };
    vector<int> fat(N, -1);
    int s{bfs(0, fat)};
    ranges::fill(fat, -1);
    int t{bfs(s, fat)};
    vector<int> path;
    for (int u{t}; u != -1; u = fat[u]) path.emplace_back(u);
    int D{(int)path.size() - 1}, k{D / 2};
    stack<array<int, 4>> st;
    if (D & 1) {
        int u{path[k]}, v{path[k + 1]};
        st.emplace(array<int, 4>{u, v, 0, 0});
        st.emplace(array<int, 4>{v, u, 0, 1});
    } else {
        int u{path[k]};
        for (int v : G[u]) st.emplace(array<int ,4>{v, u, 1, v});
    }
    map<int, int> cnt;
    map<pair<int, int>, int> same;
    int ans{};
    while (!st.empty()) {
        auto [u, f, d, s] = st.top(); st.pop();
        if (d == k) {
            ans += cnt[A[u]] - same[{A[u], s}];
            cnt[A[u]] ++;
            same[{A[u], s}] ++;
            continue;
        }
        for (int v : G[u]) if (v != f) st.emplace(array<int, 4>{v, u, d + 1, s});
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}