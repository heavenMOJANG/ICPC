#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5;
struct segmentTree { int maxn, minn; } t[N << 2];
int n, q, h[N], low[N], high[N];
void pushUp(int p) {
    t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);
    t[p].minn = min(t[p << 1].minn, t[p << 1 | 1].minn);
}
void build(int p, int pl, int pr) {
    if (pl == pr) {
        t[p].maxn = low[pl];
        t[p].minn = high[pl];
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
pair<int, int> query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return {t[p].maxn, t[p].minn};
    int mid = pl + pr >> 1, resMax = LLONG_MIN, resMin = LLONG_MAX;
    if (L <= mid) {
        auto [x, y] = query(L, R, p << 1, pl, mid);
        resMax = max(resMax, x);
        resMin = min(resMin, y);
    }
    if (R > mid) {
        auto [x, y] = query(L, R, p << 1 | 1, mid + 1, pr);
        resMax = max(resMax, x);
        resMin = min(resMin, y);
    }
    return {resMax, resMin};
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> h[i];
    for (int i = 2; i <= n; ++ i) low[i] = min(h[i], h[i - 1]), high[i] = max(h[i], h[i + 1]);

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}