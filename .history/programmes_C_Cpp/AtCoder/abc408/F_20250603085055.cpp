#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define ls p << 1
#define rs p << 1 | 1
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
int t[N << 2];
void pushUp(int p) { t[p] = max(t[ls], t[rs]); }
void build(int p, int pl, int pr) {
    if (pl == pr) { t[p] = -INF; return; }
    int mid = pl + pr >> 1;
    build(ls, pl, mid);
    build(rs, mid + 1, pr);
    pushUp(p);
}
void update(int p, int pl, int pr, int idx, int d) {
    if (pl == pr) { t[p] = d; return; }
    int mid = pl + pr >> 1;
    if (idx <= mid) update(ls, pl, mid, idx, d);
    else update(rs, mid + 1, pr, idx, d);
    pushUp(p);
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return t[p];
    int mid = pl + pr >> 1, res = max(query(L, R, ls, pl, mid), query(L, R, rs, mid + 1, pr));
    return res;
}
void solve() {
    int n, d, r; cin >> n >> d >> r;
    vector<int> h(n), p(n);
    for (int i{}; i < n; ++ i) cin >> h[i], h[i] --, p[h[i]] = i;
    vector<int> dp(n, 0);
    for (int i{}; i < n; ++ i) {
        if (i >= d) update(0, 0, n - 1, p[i - d], dp[i - d]);
        int maxn = query(max(0ll, p[i] - r), min(n - 1, p[i] + r), 0, 0, n - 1);
        dp[i] = max(dp[i], maxn + 1);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}