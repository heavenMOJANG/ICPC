#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, x, a[N], diff[N];
void stInit() {
    
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
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}