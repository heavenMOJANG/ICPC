#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
using S = int;
S op(S a, S b) { return a + b; }
S e() { return 0ll; }
void solve() {
    int n, q; cin >> n >> q;
    vector<int> to_seg(n);
    for (auto && x : to_seg) cin >> x;
    segtree<S, op, e> seg(to_seg);
    while (q --) {
        int opt; cin >> opt;
        if (opt == 1) {
            int x; cin >> x; x --;
            int a = seg.get(x), b = seg.get(x + 1);
            seg.set(x, b);
            seg.set(x + 1, a);
        }
        if (opt == 2) {
            int l, r; cin >> l >> r; l --, r --;
            cout << seg.prod(l, r + 1) << "\n";
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