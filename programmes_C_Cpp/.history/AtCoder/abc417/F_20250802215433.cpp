#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 2e5 + 10;
int inv[N];
int qpow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
};
struct segtree {
    struct Node { int sum, ok, tag; };
    int n;
    vector<Node> st;
    segtree(int _n): n(_n) { st.assign((n << 2) + 4, {0, 0, 0}); }
    void build(int p, int pl, int pr, const vector<int>& A) {
        if (pl == pr) st[p].sum = A[pl];
        else {
            int mid = pl + pr >> 1;
            build(p << 1, pl, mid, A);
            build(p << 1 | 1, mid + 1, pr, A);
            st[p].sum = (st[p << 1].sum + st[p << 1 | 1].sum) % MOD;
        }
    }
    void apply(int p, int pl, int pr, int v) {
        st[p].ok = 1;
        st[p].tag = v;
        st[p].sum = v * (pr - pl + 1) % MOD;
    }
    void pushDown(int p, int pl, int pr) {
        if (!st[p].ok) return;
        int mid = pl + pr >> 1;
        apply(p << 1, pl, mid, st[p].tag);
        apply(p << 1 | 1, mid + 1, pr, st[p].tag);
        st[p].ok = 0;
    }
    void update(int p, int pl, int pr, int L, int R, int v) {
        if (L > pr || R < pl) return;
        if (L <= pl && pr <= R) { apply(p, pl, pr, v); return; }
        pushDown(p, pl, pr);
        int mid = pl + pr >> 1;
        update(p << 1, pl, mid, L, R, v);
        update(p << 1 | 1, mid + 1, pr, L, R, v);
        st[p].sum = (st[p << 1].sum + st[p << 1 | 1].sum) % MOD;
    }
    int query(int p, int pl, int pr, int L, int R) {
        if (L > pr || R < pl) return 0;
        if (L <= pl && pr <= R) return st[p].sum;
        pushDown(p, pl, pr);
        int mid = pl + pr >> 1;
        return (query(p << 1, pl, mid, L, R) + query(p << 1 | 1, mid + 1, pr, L, R)) % MOD;
    }
    void collect(int p, int pl, int pr, vector<int>& out) {
        if (pl == pr) out[pl] = st[p].sum;
        else {
            pushDown(p, pl, pr);
            int mid = pl + pr >> 1;
            collect(p << 1, pl, mid, out);
            collect(p << 1 | 1, mid + 1, pr, out);
        }
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i], a[i] %= MOD;
    segtree seg(n);
    seg.build(1, 1, n, a);
    for (int i{}; i < m; ++ i) {
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        int s = seg.query(1, 1, n, l, r);
        int avg = s * inv[len] % MOD;
        seg.update(1, 1, n, l, r, avg);
    }
    vector<int> ans(n + 1);
    seg.collect(1, 1, n, ans);
    for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (int i = 1; i < N; ++ i) inv[i] = qpow(i, MOD - 2);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}