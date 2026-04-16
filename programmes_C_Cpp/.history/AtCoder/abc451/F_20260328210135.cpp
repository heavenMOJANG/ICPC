#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
constexpr int INF = 0x7fffffff;
struct DSU {
    vector<int> fat, siz, xr, c0, c1;
    int ans{}, bi = 1;
    DSU (int n) : fat(n + 1), siz(n + 1, 1), xr(n + 1, 0), c0(n + 1, 1), c1(n + 1, 0) {
        iota(fat.begin(), fat.end(), 0);
    }
    pair<int, int> find(int i) {
        if (fat[i] == i) return {i, 0ll};
        auto [rt, p] = find(fat[i]);
        fat[i] = rt;
        xr[i] = xr[i] ^ p;
        return {fat[i], xr[i]};
    }
    void merge(int u, int v) {
        if (!bi) return;
        pair<int, int> ru = find(u);
        pair<int, int> rv = find(v);
        if (ru.fi == rv.fi) { if (ru.se == rv.se) bi = 0; return; }
        int r1 = ru.fi, r2 = rv.fi;
        if (siz[r1] > siz[r2]) swap(r1, r2), swap(ru, rv);
        ans -= min(c0[r1], c1[r1]);
        ans -= min(c0[r2], c1[r2]);
        fat[r1] = r2;
        int val = ru.se ^ rv.se ^ 1;
        xr[r1] = val;
        if (val == 0) c0[r2] += c0[r1], c1[r2] += c1[r1];
        else c0[r2] += c1[r1], c1[r2] += c0[r1];
        siz[r2] += siz[r1];
        ans += min(c0[r2], c1[r2]);
    }
};
void solve() {
    int N, Q; cin >> N >> Q;
    DSU dsu(N);
    for (int i{}; i < Q; ++ i) {
        int u, v; cin >> u >> v;
        dsu.merge(u, v);
        if (!dsu.bi) cout << "-1\n";
        else cout << dsu.ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}