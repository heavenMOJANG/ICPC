#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
struct Tree {
    int val, tag;
}t[N << 2];
int n, a[N];
void pushUp(int p) {t[p].val = t[p << 1].val + t[p << 1 | 1].val; }
void build(int p, int pl, int pr) {
    if (pl == pr) { t[p].val = a[pl]; return; }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n);
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}