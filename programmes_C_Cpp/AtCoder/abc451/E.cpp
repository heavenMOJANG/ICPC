#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i{}; i < N; ++ i)
        for (int j = i + 1; j < N; ++ j) {
            int x; cin >> x;
            A[i][j] = A[j][i] = x;
        }
    vector<int> mind(N, INF), fa(N, -1), in(N, 0);
    mind[0] = 0;
    for (int dep{}; dep < N; ++ dep) {
        int u = -1, bd = INF;
        for (int i{}; i < N; ++ i)
            if (!in[i] && mind[i] < bd) bd = mind[i], u = i;
        if (u == -1) break;
        in[u] = 1;
        for (int v{}; v < N; ++ v)
            if (!in[v] && A[u][v] < mind[v]) mind[v] = A[u][v], fa[v] = u;
    }
    vector<vector<pair<int, int>>> tr(N);
    for (int i = 1; i < N; ++ i) {
        tr[i].emplace_back(fa[i], A[i][fa[i]]);
        tr[fa[i]].emplace_back(i, A[i][fa[i]]);
    }
    int ok = 1;
    for (int i{}; i < N; ++ i) {
        vector<pair<int, int>> stk;
        stk.emplace_back(i, -1);
        vector<int> dis(N, 0);
        while (!stk.empty()) {
            int u = stk.back().first, p = stk.back().second;
            stk.pop_back();
            if (A[i][u] != dis[u]) { ok = 0; break; }
            for (auto [v, w] : tr[u]) {
                if (v != p) dis[v] = dis[u] + w, stk.emplace_back(v, u);
            }
        }
        if (!ok) break;
    }
    cout << (ok ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}