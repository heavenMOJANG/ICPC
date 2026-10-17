#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int val, mn; };
S op(S a, S b) { return {a.val + b.val, min(a.mn, a.val + b.mn)}; }
S e() { return {0, 0}; }
S get(char c) {
    int x{c == 'A' ? 1 : -1};
    return {x, min(0ll, x)};
}
void solve() {
    int N; cin >> N;
    string ST; cin >> ST;
    vector<S> to_seg(N);
    for (int i : views::iota(0, N)) to_seg[i] = get(ST[i]);
    segtree<S, op, e> seg(to_seg);
    int Q; cin >> Q;
    while (Q --) {
        int opt; cin >> opt;
        if (opt == 1) {
            int i;
            char c;
            cin >> i >> c, i --;
            seg.set(i, get(c));
        } else {
            int l, r; cin >> l >> r, l --;
            cout << (seg.prod(l, r).mn >= 0 ? "Yes\n" : "No\n");
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