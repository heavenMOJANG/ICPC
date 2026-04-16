#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
struct S { int val; };
S op(S a, S b) { return {(a.val + b.val) % MOD}; }
S e() { return {0ll} ; }
using F = int;
S mapping(F f, S x) { return x.val * f % MOD; }
F composition(F f, F g) { return f * g % MOD; }
F id() { return 1ll; }
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> seg(N);
    for (int i{}; i < M; ++ i) {
        int x, y; cin >> x >> y;
        seg[y - 1].emplace_back(x);
    }
    vector<int> fac(M + 1, 1);
    for (int i = 1; i <= M; ++ i) fac[i] = fac[i - 1] * 2 % MOD;
    vector<S> to_seg(N, {0});
    to_seg[0] = {1};
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(to_seg);
    int tot = 1;
    for (int r = 1; r < N; ++ r) {
        auto v = seg[r];
        sort(v.begin(), v.end());
        int m = v.size();
        (tot *= fac[m]) %= MOD;
        int L{}, used{};
        for (int i{}; i < m;) {
            int x = v[i], j = i;
            while (j < m && v[j] == x) j ++;
            int R = x - 2;
            if (L <= R) seg.apply(L, R + 1, fac[m - used]);
            used += j - i;
            L = x - 1;
            i = j;
        }
        if (L <= r - 1) seg.apply(L, r, fac[m - used]);
        int sum = seg.prod(0, r).val;
        int val = (tot - sum + MOD) % MOD;
        seg.set(r, { (seg.get(r).val + val) % MOD});
    }
    cout << seg.get(N - 1).val % MOD << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}