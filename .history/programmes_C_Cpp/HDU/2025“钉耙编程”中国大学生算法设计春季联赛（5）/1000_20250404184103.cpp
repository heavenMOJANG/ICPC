#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int dp[405][405][405];
void solve() {
    int n, m, v; cin >> n >> m >> v;
    vector dp(m + 1, vector<int> (v + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++ i)
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}