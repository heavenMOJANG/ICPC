#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct segmentTree {
    int val, tag;
} t[N << 2];
int a[N];
void pushUp(int p) {
    t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}
void build(int p, int pl, int pr) {
    if (pl == pr) {
        t[p] = {a[pl], 0};
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void addTag(int p, int pl, int pr, int d) {
    t[p].tag += d;
    t[p].val += d * (pr - pl + 1);
}
void pushDown(int p, int pl, int pr) {
    int mid = pl + pr >> 1;
    addTag(p << 1, pl, mid, t[p].tag);
    addTag(p << 1 | 1, mid + 1, pr, t[p].tag);
    t[p].tag = 0;
}
void update(int L, int R, int p, int pl, int pr, int d) {
    if (L <= pl && pr <= R) {
        t[p].val += d * (pr - pl + 1);
        t[p].val += d;
        return;
    }
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1;
    if (L <= mid) update(L, R, p << 1, pl, mid, d);
    if (R > mid) update(L, R, p << 1 | 1, mid + 1, pr, d);
    pushUp(p);
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return t[p].val;
    pushDown(p, pl, pr);
    int mid = pl + pr >> 1, res{};
    if (L <= mid) res += query(L, R, p << 1, pl, mid);
    if (R > mid) res += query(L, R, p << 1 | 1, mid + 1, pr);
    return res;
}
void solve() {
    int n, d, k; cin >> n >> d >> k;
    build(1, 1, n);
    while (k --) {
        int l, r; cin >> l >> r;
        update(max(1ll, l - d + 1), r, 1, 1, n, 1);
    }
    int minn = 1, maxn = 1;
    int minCur = query(1, 1, 1, 1, n), maxCur = query(1, 1, 1, 1, n);
    for (int i = 1; i <= n - d + 1; ++ i) {
        int cur = query(i, i, 1, 1, n);
        if (cur < minCur) {
            minCur = cur;
            minn = i;
        }
        if (cur > maxCur) {
            maxCur = cur;
            maxn = i;
        }
    }
    cout << maxn << " " << minn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}