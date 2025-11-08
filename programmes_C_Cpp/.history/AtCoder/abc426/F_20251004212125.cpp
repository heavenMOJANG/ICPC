#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
#define i128 __int128
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { i128 val; };
using F = i128;
S op (S a, S b) { return {min(a.val, b.val)}; }
S e() { return {(i128)1 << 120}; }
S mapping (F f, S x) { return {x.val + f}; }
F composition (F f, F g) { return f + g; }
F id() { return 0; }
void write(i128 n) {
    if (n < 0) {putchar('-'); n *= -1;}
    static __int128 sta[256];
    i128 top{};
    do {
        sta[top ++] = n % 10, n /= 10;
    } while(n);
    while(top) putchar(sta[-- top] + 48);
}
void solve() {
    int n; cin >> n;
    vector<S> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i].val;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    for (int i{}; i < n; ++ i) seg.set(i, a[i]);
    int q; cin >> q;
    for (int i{}; i < q; ++ i) {
        int l, r, k; cin >> l >> r >> k;
        seg.apply(l - 1, r, -k);
        i128 ans = k * (r - l + 1);
        auto f = [](S x) { return x.val >= 0; };
        for (;;) {
            S sum = seg.prod(l - 1, r);
            if (sum.val > 0) break;
            int p = seg.max_right(l - 1, f);
            if (p >= r) break;
            S cur = seg.get(p);
            ans += cur.val;
            seg.apply(p, p + 1, -cur.val);
        }
        write(ans); puts("");
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}