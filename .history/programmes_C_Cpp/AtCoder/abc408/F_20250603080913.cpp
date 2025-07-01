#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define ls p << 1
#define rs p << 1 | 1
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
struct segtree { int val = -1e9, tag = 0; } t[N << 2];
void pushUp(int p) { t[p].val = max(t[ls].val, t[rs].val); }
void build(int p, int pl, int pr) {
    if (pl == pr) { return; }
    int mid = pl + pr >> 1;
    build(ls, pl, mid);
    build(rs, mid + 1, pr);
    pushUp(p);
}

void solve() {
    int n, d, r; cin >> n >> d >> r;
    vector<int> h(n), p(n);
    for (int i{}; i < n; ++ i) cin >> h[i], h[i] --, p[h[i]] = i;
    vector<int> dp(n, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}