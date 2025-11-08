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
string trans(i128 n) {
    string res = "";
    if (n == 0) return "0";
    int flag{};
    if (n < 0) flag = 1, n *= -1;
    while (n) {
        res += (n % 10) + '0';
        n /= 10;
    }
    if (flag) res += '-';
    reverse(res.begin(), res.end());
    return res;
}
void solve() {
    int n; cin >> n;
    vector<S> a(n);
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        a[i].val = x;
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    for (int i{}; i < n; ++ i) seg.set(i, a[i]);
    int q; cin >> q;
    int q; cin >> q;
    while (q--) {
        int l, r, k; long long kk;
        cin >> l >> r >> k;
        int L = l - 1, R = r;
        seg.apply(L, R, -k);
        i128 ans = (i128)k * (r - l + 1);
        auto f = [](S x) { return x.val >= (i128)0; };
        for (;;) {
            S prod = seg.prod(L, R);
            if (prod.val >= (i128)0) break;
            int pos = seg.max_right(L, f);
            if (pos >= R) break;
            S cur = seg.get(pos);
            ans += cur.val;
            seg.apply(pos, pos + 1, -cur.val);
        }
        cout << trans(ans) << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}