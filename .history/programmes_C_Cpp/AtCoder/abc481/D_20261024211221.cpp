#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M, S, T; cin >> N >> M >> S >> T;
    vector<vector<int>> G(N + 1);
    for (int i : views::iota(0, M)) {
        int A, B; cin >> A >> B;
        G[A].emplace_back(B);
    }
    vector<int> dis(N + 1, INF);
    deque<int> dq;
    dis[S] = 0;
    dq.push_front(S);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        if (G[u].empty()) continue;
        int minn{*min_element(G[u].begin(), G[u].end())};
        for (int v : G[u]) {
            int cost{v == minn ? 0 : 1};
            if (dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                if (cost == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    cout << (dis[T] == INF ? -1 : dis[T]) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}