#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, x, a[N], diff[N], st[N][20], lg2[N];
void stInit() {
    for (int i = 1; i <= n; ++ i) st[i][0] = a[i];
    for (int j = 1; j <= lg2[n]; ++ j)
        for (int i = 1; i + (1 << j) < n; ++ i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); 
}
int query(int l, int r) {
    int k = lg2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 2; i <= n; ++ i) diff[i] = abs(a[i] - a[i - 1]);
    for (int i = 2; i <= n; ++ i) diff[i] += diff[i - 1];

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    lg2[1] = 0; lg2[2] = 1;
    for (int i = 3; i < N; ++ i) lg2[i] = lg2[i / 2] + 1;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}