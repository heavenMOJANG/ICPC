#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e4 + 10;
struct Node {
    int min, max;
}t[N << 2];
int n, q, a[N];
void pushUp(int p) {
    t[p].min = min(t[p << 1].min, t[p << 1 | 1].min);
    t[p].max = max(t[p << 1].max, t[p << 1 | 1].max);
}
void build(int p, int pl, int pr) {
    if (pl == pr) {
        t[p].min = t[p].max = a[pl];
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
pair<int, int> query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return minmax(t[p].min, t[p].max);
    int mid = pl + pr >> 1;
    pair<int, int> res;
    int resMin = LLONG_MAX, resMax = LLONG_MIN;
    if (L <= mid) {
        res = query(L, R, p << 1, pl, mid);
        resMin = min(resMin, res.first);
        resMax = max(resMax, res.second);
    }
    if (R > mid) {
        res = query(L, R, p << 1 | 1, mid + 1, pr);
        resMin = min(resMin, res.first);
        resMax = max(resMax, res.second);
    }
    return {resMin, resMax};
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; ++ i) {
        int l, r; cin >> l >> r;
        pair<int, int> ans = query(l, r, 1, 1, n);
        cout << ans.second - ans.first << "\n";
    }
    return 0;
}