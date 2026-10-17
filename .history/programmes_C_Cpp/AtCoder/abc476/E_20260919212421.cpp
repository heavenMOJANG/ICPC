#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { pair<int, int> minn, maxn; };
S op(S a, S b) { return {min(a.minn, b.minn), max(a.maxn, b.maxn)}; }
S e() { return {{INF, -1}, {-INF, -1}}; }
void solve() {
    int N, M; cin >> N >> M;
    vector<int> P(N); for (auto && x : P) cin >> x;
    vector<S> to_seg(N);
    for (int i : views::iota(0, N))
        to_seg[i] = {{P[i], i}, {P[i], i}};
    segtree<S, op, e> seg(to_seg);
    while (M --) {
        int L, R; cin >> L >> R, L --;
        S res{seg.prod(L, R)};
        int x{res.minn.second}, y{res.maxn.second};
        swap(P[x], P[y]);
        seg.set(x, {{P[x], x}, {P[x], x}});
        seg.set(y, {{P[y], y}, {P[y], y}});
    }
    for (int i : views::iota(0, N)) cout << P[i] << " \n"[i == N - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}