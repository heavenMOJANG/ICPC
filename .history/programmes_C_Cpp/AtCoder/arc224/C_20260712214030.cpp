#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> G[N];
    for (int i{}; i < M; ++ i) {
        int u, v; cin >> u >> v, u --, v --;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> dep(N, -1), nxt(N, 0);
    vector<int> stk;
    dep[0] = 0;
    stk.emplace_back(0);
    while (!stk.empty()) {
        int v{stk.back()};
        if (nxt[v] == (int)G[v].size()) {
            stk.pop_back();
            continue;
        }
        int to{G[v][nxt[v] ++]};
        if (dep[to] != -1) continue;
        dep[to] = dep[v] + 1;
        stk.emplace_back(to);
    }
    for (int i{}; i < N; ++ i) cout << dep[i] << " \n"[i + 1 == N];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}