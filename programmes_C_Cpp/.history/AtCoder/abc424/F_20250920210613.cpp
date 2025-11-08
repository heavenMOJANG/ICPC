#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
using namespace std;
using pii = pair<int, int>;
constexpr int INF = 0x7fffffff;
pii op(pii a, pii b) { return {min(a.first, b.first), max(a.second, b.second)}; }
pii e() { return {INF, -INF}; }
void solve() {
    int n, q; cin >> n >> q;
    atcoder::segtree<pii, op, e> seg(n);
    vector<int> f(n, -1);
    while (q --) {
        int a, b; cin >> a >> b, a --, b --;
        if (a > b) swap(a, b);
        int ok = 1, l = a + 1, r = b - 1;
        if (l <= r) {
            pii p = seg.prod(l, r + 1);
            int minn = p.first, maxn = p.second;
            if (minn <= a || maxn >= b) ok = 0;
        }
        if (ok) {
            cout << "Yes\n";
            f[a] = b;
            f[b] = a;
            seg.set(a, {b, b});
            seg.set(b, {a, a});
        } else cout << "No\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}