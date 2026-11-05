#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
using F = int;
constexpr int INF = LLONG_MAX;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }
F mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}