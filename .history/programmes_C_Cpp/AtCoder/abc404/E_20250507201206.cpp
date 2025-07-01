#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e3 + 10;
int a[N], c[N], tr[N << 2];
void build(int p, int pl, int pr) {
    if (pl == pr) { tr[p] = pl - c[pl]; }
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> c[i];
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}