#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
void solve() {
    int n; cin >> n;
    vector<int> a(n), dp(N);
    vector nxt(n + 10, vector<int>(20, 0));
    for (auto && x : a) cin >> x;
    for (int j = 0; j < 20; ++ j) nxt[n][j] = nxt[n + 1][j] = n + 1;
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = 0; j < 20; ++ j) nxt[i][j] = nxt[i + 1][j];
        nxt[i][a[i] - 1] = i + 1;
    }
    for (int i = 0; i < (1ll << 20); ++ i) dp[i] = n + 1;
    dp[0] = 0;
    /*
    int maxn{};
    for (int i = 0; i < (1ll < 20); ++ i) {
        int cnt{};
        for (int j = 0; j < 20; ++ j)
            if ((i >> j) & 1) {
                cnt += 2;
                dp[i] = min(dp[i], nxt[nxt[dp[i ^ (1ll << j)]][j]][j]);
            }
        if (dp[i] <= n) maxn = max(maxn, cnt);
    }
    cout << maxn << "\n";
    */
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}