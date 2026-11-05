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
    vector<int> ans(N + 1, -1);
    queue<vector<int>> q;
    ans[1] = 0;
    q.push({1});
    while (!q.empty()) {
        auto cur = move(q.front()); q.pop();
        vector<int> bk[10];
        for (int u : cur)
            for (auto [c, v] : G[u]) bk[c].emplace_back(v);
        for (int c : views::iota(1, 10)) {
            vector<int> nxt;
            for (int v : bk[c]) {
                if (ans[v] != -1) continue;
                ans[v] = (ans[cur[0]] * 10 + c) % MOD;
                nxt.emplace_back(v);
            }
            if (nxt.empty()) q.push(move(nxt));
        }
    }
    for (int i : views::iota(2, N + 1)) cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}