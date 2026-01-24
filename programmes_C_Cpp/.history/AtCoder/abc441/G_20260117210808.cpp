#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int max, cnt, len; };
struct F { int add, flip; };
S op (S a, S b) {
    return { max(a.max, b.max), a.cnt + b.cnt, a.len + b.len };
}
S e () { return {0ll, 0ll, 0ll}; }
S mapping (F f, S s) {
    if (f.flip) {
        s.max = 0;
        s.cnt = s.len - s.cnt;
    }
    if (f.add && s.cnt) s.max += f.add;
    return s;
}
F composition (F f, F g) {
    if (f.flip) {
        g.flip ^= 1;
        g.add = 0;
    }
    g.add += f.add;
    return g;
}
F id () { return {0ll, 0ll}; }
void solve() {
    int n, q; cin >> n >> q;
    vector<S> to_seg(n);
    fill(to_seg.begin(), to_seg.end(), S{0ll, 1ll, 1ll});
    lazy_segtree<S, F, op, e, mapping, composition, id> seg(to_seg);
    while (q --) {
        int opt; cin >> opt;
        switch (opt) {
            case 1: {
                int l, r, x; cin >> l >> r >> x;
                seg.apply(l - 1, r, {x, 0ll});
            }break;
            case 2: {
                int l, r; cin >> l >> r;
                seg.apply(l - 1, r, {0ll, 1ll});
            }break;
            case 3: {
                int l, r; cin >> l >> r;
                cout << seg.prod(l - 1, r).max << '\n';
            }break;
        }
    }
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}