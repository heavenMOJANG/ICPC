#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int maxu, minu, maxv, minv; };
struct F {
    int f, u, v;
    F(): f(0), u(0), v(0) {}
    F(int f, int u, int v): f(f), u(u), v(v) {}
};
S op(S a, S b) {
    return S{max(a.maxu, b.maxu), min(a.minu, b.minu), max(a.maxv, b.maxv), min(a.minv, b.minv)};
}
S e() { return S{-INF, INF, -INF, INF}; }
S mapping(F f, S s) {
    if (!f.f) return s;
    return S{f.u, f.u, f.v, f.v};
}
F composition(F f, F g) {
    if (g.f) return g;
    return f;
}
F id() { return F(); }
void solve() {
    int n, q; cin >> n >> q;
    vector<int> x(n), y(n);
    for (int i{}; i < n; ++ i) cin >> x[i] >> y[i];
    vector<S> to_seg(n);
    for (int i{}; i < n; ++ i) {
        int u = x[i] + y[i];
        int v = x[i] - y[i];
        to_seg[i] = S{u, u, v, v};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(to_seg);
    while (q --) {
        int opt; cin >> opt;
        if (opt == 1) {
            int i, X, Y; cin >> i >> X >> Y, i --;
            seg.apply(i, i + 1, F(1, X + Y, X - Y));
        } else {
            int l, r, X, Y;
            cin >> l >> r >> X >> Y, l --, r --;
            int u = X + Y, v = X - Y;
            S res = seg.prod(l, r + 1);
            int ans = max({abs(res.maxu - u), abs(res.minu - u), abs(res.maxv - v), abs(res.minv - v)});
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