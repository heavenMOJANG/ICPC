#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 +10;
int n, k, a[N], rk[N];
vector<int> pos[N];
pair<int, int> operator + (const pair<int, int> & x, const pair<int, int> & y) {
    if (x.first > y.first) return x;
    if (x.first < y.first) return y;
    return {x.first, x.second + y.second};
}
class segmentTree {
private:
    pair<int, int> Node[N << 2];
    int tag[N << 2];
    void apply(int p, int val) {
        Node[p].first += val;
        tag[p] = val;
    }
    void pushDown(int p) {
        if (tag[p]) {
            apply(p << 1, tag[p]);
            apply(p << 1 | 1, tag[p]);
            tag[p] = 0;
        }
    }
public:
    void build(int p = 1, int pl = 1, int pr = n) {
        Node[p] = {0, pr - pl + 1};
        tag[p] = 0;
        if (pl == pr) return;
        int mid = pl + pr  >> 1;
        build(p << 1, pl, mid);
        build(p << 1 | 1, mid + 1, pr);
    }
    void modify(int L, int R, int val, int p = 1, int pl = 1, int pr = n) {
        if (L <= pl && pr <= R) return apply(p, val);
        pushDown(p);
        int mid = pl + pr >> 1;
        if (L <= mid) modify(L, R, val, p << 1, pl, mid);
        if (R > mid) modify(L, R, val, p << 1 | 1, mid + 1, pr);
        Node[p] = Node[p << 1] + Node[p << 1 | 1];
    }
    pair<int, int> query(int L, int R, int p = 1, int pl = 1, int pr = n) {
        if (L <= pl && pr <= R) return Node[p];
        pushDown(p);
        int mid = pl + pr >> 1;
        if (L <= mid) return query(L, R, p << 1, pl, mid);
        if (R > mid) return query(L, R, p << 1 | 1, mid + 1, pr);
        return query(L, R, p << 1, pl, mid) + query(L, R, p << 1 | 1, mid + 1, pr);
    }
}seg;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> a[i], rk[i] = a[i];
    sort(rk + 1, rk + 1 + n);
    int m = unique(rk + 1, rk + 1 + n) - rk - 1;
    for (int i = 1; i <= n; ++ i) a[i] = lower_bound(rk + 1, rk + m + 1, a[i]) - rk;
    seg.build();
    int ans = 0;
    for (int i = 1; i <= m; ++ i) pos[i] = {0};
    for (int i = 1; i <= n; ++ i) {
        seg.modify(i, i, m);
        seg.modify(pos[a[i]].back() + 1, i, m);
        if (pos[a[i]].size() >= k + 1)
            seg.modify(pos[a[i]][pos[a[i]].size() - k - 1] + 1, pos[a[i]][pos[a[i]].size() - k], - 1);
        pos[a[i]].emplace_back(i);
        if (pos[a[i]].size() >= k + 1)
            seg.modify(pos[a[i]][pos[a[i]].size() - k - 1] + 1, pos[a[i]][pos[a[i]].size() - k], 1);
        pair<int, int> t = seg.query(1, i);
        if (t.first == m) ans += t.second;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}