#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e3 + 10;
int a[N], c[N], v[N], tr[N << 2];
void build(int p, int pl, int pr) {
    if (pl == pr) { tr[p] = v[pl]; return; }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    tr[p] = min(tr[p << 1], tr[p << 1 | 1]);
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return tr[p];
    int mid = pl + pr >> 1, res = LLONG_MAX;
    if (L <= mid) res = min(res, query(L, R, p << 1, pl, mid));
    if (R > mid) res = min(res, query(L, R, p << 1 | 1, mid + 1, pr));
    return res;
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++ i) cin >> c[i], v[i] = i - c[i];
    for (int i = 1; i < n; ++ i) cin >> a[i];
    build(1, 1, n - 1);
    int res{}, pre{};
    for (int i = 1; i < n; ++ i)
        if (a[i]) {
            int l = i;
            while (pre < l) {
                int nl = query(l, i, 1, 1, n - 1);
                if (nl >= l) break;
                res ++;
                l = nl;
            }
            pre = i;
        }
    cout << res << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}