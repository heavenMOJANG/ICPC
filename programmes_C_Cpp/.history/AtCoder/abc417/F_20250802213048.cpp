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
        int sum;
        bool has_lazy;
        int lazy_val;
    };
    int n;
    vector<Node> st;
    segtree(int _n): n(_n) { st.assign(4*n+4, {0, 0, 0}); }
    void build(int p, int l, int r, const vector<int>& A) {
        if (l == r) {
            st[p].sum = A[l];
        } else {
            int m = (l+r)/2;
            build(p<<1, l, m, A);
            build(p<<1|1, m+1, r, A);
            st[p].sum = add(st[p<<1].sum, st[p<<1|1].sum);
        }
    }
    void apply_set(int p, int l, int r, int v) {
        st[p].has_lazy = true;
        st[p].lazy_val = v;
        st[p].sum = mul(v, r-l+1);
    }
    void push(int p, int l, int r) {
        if (!st[p].has_lazy) return;
        int m = (l+r)/2;
        apply_set(p<<1, l, m, st[p].lazy_val);
        apply_set(p<<1|1, m+1, r, st[p].lazy_val);
        st[p].has_lazy = false;
    }
    // range assign [L,R] = v
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
        st[p].sum = add(st[p<<1].sum, st[p<<1|1].sum);
    }
    // range sum query
    int query_sum(int p, int l, int r, int L, int R) {
        if (L>r || R<l) return 0;
        if (L<=l && r<=R) {
            return st[p].sum;
        }
        push(p, l, r);
        int m = (l+r)/2;
        return add(
            query_sum(p<<1, l, m, L, R),
            query_sum(p<<1|1, m+1, r, L, R)
        );
    }
    // extract final values
    void collect(int p, int l, int r, vector<int>& out) {
        if (l==r) {
            out[l] = st[p].sum;
        } else {
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

    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    fac[0] = fac[1] = 1;
    for (int i = 2; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}