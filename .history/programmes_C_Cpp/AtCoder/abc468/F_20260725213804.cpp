#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
using S = int;
using F = int;
S op(S a, S b) { return max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) {
    if (x == -INF) return -INF;
    return f + x;
}
F composition(F f, F g) { return f + g; }
F id() { return 0ll; }
void solve() {
    int N; cin >> N;
    vector<int> P(N + 1);
    for (int i : views::iota(1, N + 1)) cin >> P[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(N + 1);
    seg.set(0, 1);
    for (int i : views::iota(2, N + 1)) {
        int ml{seg.prod(0, P[i])}, mr{seg.prod(P[i], N + 1)};
        int res{-INF};
        if (ml != -INF) res = max(res, ml + 1);
        if (mr != -INF) res = max(res, mr);
        if (P[i] > P[i - 1]) seg.apply(0, N + 1, 1);
        seg.set(P[i - 1], max(seg.get(P[i - 1]), res));
    }
    cout << seg.prod(0, N + 1) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}