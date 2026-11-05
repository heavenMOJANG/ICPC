#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> G(N + 1);
    for (int i : views::iota(0, M)) {
        int A, B, C; cin >> A >> B >> C;
        G[A].emplace_back(C, B);
    }
    for (int i : views::iota(1, N + 1)) sort(G[i].begin(), G[i].end());
    vector<int> ans(N + 1, -1);
    queue<int> q;
    ans[1] = 0; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& [c, v] : G[u]) {
            if (ans[v] != -1) continue;
            ans[v] = (ans[v] * 10 + c) % MOD;
            q.push(v);
        }
    }
    for (int i : views::iota(2, N + 1)) cout << ans[i] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}