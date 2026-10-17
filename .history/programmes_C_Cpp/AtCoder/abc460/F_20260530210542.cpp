#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int minD, maxX, Lmax, Rmax, ans; };
S op(S a, S b) {
    return {
        min(a.minD, b.minD),
        max(a.maxX, b.maxX),
        max({a.Lmax, b.Lmax, a.maxX - b.minD}),
        max({a.Rmax, b.Rmax, b.maxX - a.minD}),
        max({a.ans, b.ans, a.Lmax + b.maxX, a.maxX + b.Rmax})
    };
}
S e() { return {INF, -INF, -INF, -INF, -INF}; }
void solve() {
    int N; cin >> N;
    vector<int> G[N + 1], stk(N + 1), clr(N + 1, 0), eul, dep;
    function<void(int, int, int)> dfs = [&](int u, int f, int d) {
        stk[u] = eul.size();
        eul.emplace_back(u);
        dep.emplace_back(d);
        for (int v : G[u]) {
            if (v != f) {
                dfs(v, u, d + 1);
                eul.emplace_back(u);
                dep.emplace_back(d);
            }
        }
    };
}

vector<int> eul, dep, stk, clr;
void dfs(int u, int f, int d) {
    stk[u] = eul.size();
    eul.emplace_back(u);
    dep.emplace_back(d);
    for (int v : G[u]) {
        if (v != f) {
            dfs(v, u, d + 1);
            eul.emplace_back(u);
            dep.emplace_back(d);
        }
    }
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> N;
    for (int i{}; i < N - 1; ++ i) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    return 0;
}
