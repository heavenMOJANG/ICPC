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
    int M{P[1]};
    for (int i : views::iota(2, N + 1))
        if (P[i] > M) {
            int max_val = seg.all_prod();
            seg.apply(0, N + 1, 1);       
            seg.set(M, max_val + 1);      
            M = P[i];
        } else {
            int ml{seg.prod(0, P[i])};   
            if (ml != -INF) seg.set(P[i], max(seg.get(P[i]), ml + 1));
        }
    cout << seg.all_prod() << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}