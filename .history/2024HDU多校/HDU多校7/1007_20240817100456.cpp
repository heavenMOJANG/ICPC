#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int t[N << 4];
void pushUp(int p) {t[p] = max(t[p << 1], t[p << 1 | 1]);}
void build(int p, int pl, int pr) {
    if (pl == pr) {t[p] = 0; return;}
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void update(int p, int pl, int pr, int x, int val) {
    if (pl == pr) {t[p] = val; return;}
    int mid = pl + pr >> 1;
    if (mid >= x) update(p << 1, pl, mid, x, val);
    else update(p << 1 | 1, mid + 1, pr, x, val);
    pushUp(p);
}
void query(int p, int pl, int pr, int L, int R) {
    if (L <= pl && pr <= R) return t[p];
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1), pre1(n + 1), pre2(n + 1), f(n + 1), b;
    set<int> s;
    for (int i = 1; i <= n; ++ i) cin >> a[i], s.insert(a[i]);
    for (auto it : s) b.emplace_back(it);
    int sizB = b.size();
    function<int(int, int, int, int, int)> query = [&](int L, int R, int p, int pl, int pr) {
        if (L <= pl && pr <= R) return t[p];
        int mid = pl + pr >> 1, res = LLONG_MIN;
        if (L <= mid) res = max(res, query(L, R, p << 1, pl, mid));
        if (R > mid) res = max(res, query(L, R, p << 1 | 1, mid + 1, pr));
        return res;
    };
    build(1, 1, sizB);
    for (int i = 1; i <= n; ++ i) {
        int L = a[i] - k, R = a[i] + k;
        int pl = lower_bound(b.begin(), b.end(), L) - b.begin(); pl ++;
        int pr = upper_bound(b.begin(), b.end(), R) - b.begin();
        int p = lower_bound(b.begin(), b.end(), a[i]) - b.begin(); p ++;
        pre1[i] = query(pl, p, 1, 1, sizB);
        pre2[i] = query(p + 1, pr, 1, 1, sizB);
        update(1, 1, sizB, p, i);
    }
    int q; cin >> q;
    while (q --) {
        int l, r; cin >> l >> r;
        int maxn = 0;
        for (int i = l; i <= r; ++ i) f[i] = 0;
        for (int i = l; i <= r; ++ i) {
            f[i] = 1;
            if (pre1[i] >= l) f[i] = max(f[i], f[pre1[i] + 1]);
            if (pre2[i] >= l) f[i] = max(f[i], f[pre2[i] + 1]);
            maxn = max(maxn, f[i]);
        }
        cout << r - l + 1 - maxn << "\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}