#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int minn, len; };
using F = long long;
S op(S a, S b) {
    if (a.minn != b.minn) return a.minn < b.minn ? a : b;
    return {a.minn, a.len + b.len};
}
S e() { return {(int)4e18, 0ll}; }
S mapping(F f, S x) { return {x.minn + f, x.len}; }
F composition(F f, F g) { return f + g; }
F id() { return 0ll; }
struct E {
    int x, l, r, d;
    bool operator < (const E& o) const { return x < o.x; }
};
void solve() {
    int H, W, h, w, N; cin >> H >> W >> h >> w >> N;
    int A = H - h + 1, B = W - w + 1, tot = A * B;
    vector<E> v;
    vector<int> y;
    while (N --) {
        int R, C; cin >> R >> C;
        int x1 = max(1ll, R - h + 1), x2 = min(A, R);
        int y1 = max(1ll, C - w + 1), y2 = min(B, C);
        if (x1 > x2 || y1 > y2) continue;
        v.emplace_back(x1, y1, y2 + 1, 1);
        v.emplace_back(x2 + 1, y1, y2 + 1, -1);
        y.emplace_back(y1);
        y.emplace_back(y2 + 1);
    }
    if (v.empty()) { cout << tot << "\n"; return; }
    sort(v.begin(), v.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    int m = y.size() - 1;
    vector<S> to_seg(m);
    int sum{};
    for (int i{}; i < m; ++ i) {
        to_seg[i] = {0ll, y[i + 1] - y[i]};
        sum += y[i + 1] - y[i];
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(to_seg);
    auto cal = [&]() {
        auto tmp = seg.all_prod();
        return sum - (tmp.minn == 0 ? tmp.len : 0ll);
    };
    int res{}, px = v[0].x;
    for (int i{}; i < (int)v.size();) {
        int x = v[i].x;
        res += cal() * (x - px);
        while (i < (int)v.size() && v[i].x == x) {
            int l = lower_bound(y.begin(), y.end(), v[i].l) - y.begin();
            int r = lower_bound(y.begin(), y.end(), v[i].r) - y.begin();
            seg.apply(l, r, v[i].d);
            i ++;
        }
        px = x;
    }
    cout << tot - res << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}