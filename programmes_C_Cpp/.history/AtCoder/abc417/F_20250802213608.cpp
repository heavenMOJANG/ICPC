#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 2e5 + 10;
int fac[N], inv[N];
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
    struct Node {
        int sum, has_lazy, lazy_val;
    };
    int n;
    vector<Node> st;
    segtree(int _n): n(_n) { st.assign(4*n+4, {0, 0, 0}); }
    void build(int p, int l, int r, const vector<int>& A) {
        if (l == r) st[p].sum = A[l];
        else {
            int mid = l + r >> 1;
            build(p << 1, l, mid, A);
            build(p << 1 | 1, mid + 1, r, A);
            st[p].sum = (st[p << 1].sum + st[p << 1 | 1].sum) % MOD;
        }
    }
    void apply_set(int p, int l, int r, int v) {
        st[p].has_lazy = true;
        st[p].lazy_val = v;
        st[p].sum = v * (r - l + 1) % MOD;
    }
    void push(int p, int l, int r) {
        if (!st[p].has_lazy) return;
        int m = (l+r)/2;
        apply_set(p<<1, l, m, st[p].lazy_val);
        apply_set(p<<1|1, m+1, r, st[p].lazy_val);
        st[p].has_lazy = false;
    }
    void update_set(int p, int l, int r, int L, int R, int v) {
        if (L>r || R<l) return;
        if (L<=l && r<=R) {
            apply_set(p, l, r, v);
            return;
        }
        push(p, l, r);
        int m = (l+r)/2;
        update_set(p<<1, l, m, L, R, v);
        update_set(p<<1|1, m+1, r, L, R, v);
        st[p].sum = (st[p<<1].sum + st[p<<1|1].sum) % MOD;
    }
    int query_sum(int p, int l, int r, int L, int R) {
        if (L>r || R<l) return 0;
        if (L<=l && r<=R) {
            return st[p].sum;
        }
        push(p, l, r);
        int m = (l+r)/2;
        return (query_sum(p<<1, l, m, L, R) + query_sum(p<<1|1, m+1, r, L, R)) % MOD;
    }
    void collect(int p, int l, int r, vector<int>& out) {
        if (l==r) out[l] = st[p].sum;
        else {
            push(p, l, r);
            int m = (l+r)/2;
            collect(p<<1, l, m, out);
            collect(p<<1|1, m+1, r, out);
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
        int s = seg.query_sum(1, 1, n, l, r);
        int avg = s * inv[len] % MOD;
        seg.update_set(1, 1, n, l, r, avg);
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