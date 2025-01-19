#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1), t(N << 4);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    function<void(int)> pushUp = [&](int p ) {
        t[p] = max(t[p << 1], t[p << 1 | 1]);
    };
    function<void(int, int, int)> build = [&](int p, int pl, int pr) {
        if (pl == pr) {
            t[p] = 0;
            return;
        }
        int mid = pl + pr >> 1;
        build(p << 1, pl, mid);
        build(p << 1 | 1, mid + 1, pr);
        pushUp(p);
    };
    function<void(int, int, int, int, int)> update = [&](int p, int pl, int pr, int x, int val) {
        if (pl == pr) {
            t[p] = val;
            return;
        }
        int mid = pl + pr >> 1;
        if (mid >= x) update(p << 1, pl, mid, x, val);
        else update(p << 1 | 1, mid + 1, pr, x, val);
        pushUp(p);
    };
    function<int(int, int, int, int, int)> query = [&](int p, int pl, int pr, int L, int R) {
        if (L <= pl && pr <= R) return t[p];
        int mid = pl + pr >> 1, res = LLONG_MIN;
        if (L <= mid) res = max(res, query(L, R, p << 1, pl, mid));
        if (R > mid) res = max(res, query(L, R, p << 1 | 1, mid + 1, pr));
        return res;
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}