#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using pii = pair<int, int>;
constexpr int INF = 0x7fffffff;
pii op(const pii &a, const pii &b) { return {min(a.first, b.first), max(a.second, b.second)}; }
pii e() { return {INF, -INF}; }
void solve() {
    int n, q; cin >> n >> q;
    segtree<pii, op, e> seg(n);

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}