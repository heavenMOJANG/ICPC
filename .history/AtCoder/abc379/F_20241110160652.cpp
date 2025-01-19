#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class SegmentTree {
public:
    int siz{};
    vector<int> tree;
    SegmentTree(vector<int> & Info) : siz(Info.size()), tree(siz << 2, 0) {
        function<void(int, int, int)> build = [&](int p, int pl, int pr) {
            if (pl == pr) { tree[p] = Info[pl - 1]; return; }
            int mid = pl + pr >> 1;
            build (p << 1, pl, mid);
            build (p << 1 | 1, mid + 1, pr);
            tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
            return;
        };
    }
    int query(int L, int R) { return query(L, R, 1, 1, siz); }
private:
    int query(int L, int R, int p, int pl, int pr) {
        if (L <= pl && pr <= R) return tree[p];
        int mid = pl + pr >> 1, res{};
        if (L <= mid) res = max(res, query(L, R, p << 1, pl, mid));
        if (R > mid) res = max(res, query(L, R, p << 1, mid + 1, pr));
        return maxn;
    }
};
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    while (q --) {
        int l, r; cin >> l >> r;
        if (a[l] < a[r]) { cout << "0\n"; continue; }

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}