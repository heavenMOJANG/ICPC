#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int minu, maxu, minv, maxv; };
S op(S a, S b) {
    return S{min(a.minu, b.minu), max(a.maxu, b.maxu), min(a.minv, b.minv), max(a.maxv, b.maxv)};
}
S e() { return S{INF, -INF, INF, -INF}; }
void solve() {
    int n, q; cin >> n >> q;
    vector<S> to_seg(n);
    for (int i{}; i < n; ++ i) {
        int x, y; cin >> x >> y;
        int u = x + y;
        int v = x - y;
        to_seg[i] = S{u, u, v, v};
    }
    segtree<S, op, e> seg(to_seg);
    while (q --) {
        int opt; cin >> opt;
        if (opt == 1) {
            int i, x, y; cin >> i >> x >> y, i --;
            int u = x + y, v = x - y;
            seg.set(i, S{u, u, v, v});
        } else {
            int l, r, x, y;
            cin >> l >> r >> x >> y, l --, r --;
            int u = x + y, v = x - y;
            S res = seg.prod(l, r + 1);
            int ans = max({ res.maxu - u, u - res.minu, res.maxv - v, v - res.minv });
            cout << ans << "\n";
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}