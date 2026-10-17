#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i : views::iota(0, M)) {
        int A, B; cin >> A >> B;
        A --, B --;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }
    vector<int> clr(N, -1), fat(N, -1), dep(N, -1);
    queue<int> Q;
    clr[0] = 0;
    Q.push(0);
    int X{-1}, Y{-1};
    while (!Q.empty() && X == -1) {
        int u{Q.front()}; Q.pop();
        for (int v : G[u]) {
            if (clr[v] == -1) {
                clr[v] = 1 - clr[u];
                fat[v] = u;
                dep[v] = dep[u] + 1;
                Q.push(v);
            } else if (clr[v] == clr[u]) { X = u, Y = v; break; }
        }
    }
    if (X == -1) { cout << "-1\n"; return; }
    vector<int> L, R;
    int u{X}, v{Y};
    while (dep[u] > dep[v]) L.emplace_back(u), u = fat[u];
    while (dep[v] > dep[u]) R.emplace_back(v), v = fat[v];
    while (u != v) {
        L.emplace_back(u);
        R.emplace_back(v);
        u = fat[u];
        v = fat[v];
    }
    L.emplace_back(u);
    reverse(R.begin(), R.end());
    vector<int> ans{L};
    for (int w : R) ans.emplace_back(w);
    cout << ans.size() << "\n";
    for (int i : views::iota(0, (int)ans.size())) cout << ans[i] + 1 << " \n"[i == (int)ans.size() - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}