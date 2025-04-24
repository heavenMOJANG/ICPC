#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int a[3], g[16][16], dp[16];
void solve() {
    int n; cin >> n;
    for (int i{}; i < 16; ++ i)
        for (int j{}; j < 16; ++ j) g[i][j] = INF;
    for (int i{}; i < n; ++ i) {
        vector<int> b(4);
        for (int j{}; j < 4; ++ j) cin >> b[j];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    for (int i{}; i < 4; ++ i) cin >> a[i];
    while(_ --) solve();
    return 0;
}