#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, m, val[N << 2], a[N];
void build(int p, int pl, int pr) {
    if (pl == pr) {
        val[p] = a[pl];
        return;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    val[p] = min(val[p << 1], val[p << 1 | 1]);
}
void update() {
    
}
int query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return val[p];
    int mid = pl + pr >> 1, res = INT_MAX;
    if (L <= mid) res = min(res, query(L, R, p << 1, pl, mid));
    if (R > mid) res = min(res, query(L, R, p << 1 | 1, mid + 1, pr));
    return res;
}
int main() {
    cin.tie() -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n);
    vector<int> ans;
    while (m --) {
        int l, r; cin >> l >> r;
        ans.emplace_back(query(l, r, 1, 1, n));
    }
    for (int i = 0; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}