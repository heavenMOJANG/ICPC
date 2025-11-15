#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5;
struct S { int cnt, sum; };
S op(S a, S b) { return {a.cnt + b.cnt, a.sum + b.sum}; }
S e() { return {0ll, 0ll}; }
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<S> to_seg(N, e());
    for (int i = 1; i <= n; ++ i) to_seg[a[i]] = {1, a[i]};
    segtree<S, op, e> seg(to_seg);
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            int old = a[x];
            if (old == y) { a[x] = y; continue; }
            S T = seg.get(old);
            T.cnt = 1;
            T.sum -= old;
            seg.set(old, T);
            S U = seg.get(y);
            U.cnt += 1;
            U.sum += y;
            seg.set(y, U);
            a[x] = y;
        } else {
            int l, r; cin >> l >> r;
            if (l > r) { cout << n * l << "\n"; continue; }
            S L = l <= 0 ? e() : seg.prod(0, l);
            int cL = L.cnt;
            S M = seg.prod(l, r + 1);
            int s = M.sum;
            S R = r + 1 > N -
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