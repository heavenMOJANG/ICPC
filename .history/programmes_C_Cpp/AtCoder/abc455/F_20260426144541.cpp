#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
using mint = modint998244353;
struct S { mint sum, sqSum; int len; };
S op(S a, S b) {
    return {
        a.sum + b.sum,
        a.sqSum + b.sqSum,
        a.len + b.len
    };
}
S e() { return {0, 0, 0}; }
using F = mint;
S mapping(F f, S x) {
    return {
        x.sum + f * x.len,
        x.sqSum + f * 2 * x.sum + f * f * x.len,
        x.len
    };
}
F composition(F f, F g) { return f + g; }
F id() { return 0; }
void solve() {
    int N, Q; cin >> N >> Q;
    vector<S> to_seg(N, {0, 0, 1});
    lazy_segtree <S, op, e, F, mapping, composition, id> seg(to_seg);
    while (Q --) {
        int l, r, a; cin >> l >> r >> a;
        seg.apply(l - 1, r, a);
        S res = seg.prod(l - 1, r);
        mint ans = (res.sum * res.sum - res.sqSum) / 2;
        cout << ans.val() << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
