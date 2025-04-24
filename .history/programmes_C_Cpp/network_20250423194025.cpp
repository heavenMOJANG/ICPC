#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
vector g(16, vector<int>(16, INF)), dp(1 << 16, vector<int> (16, INF));
vector<int> a(4);
int get(int x) { return 15 - x; }
void solve() {
    int n; cin >> n;
    int ans = INF;
    for (int i{}; i < n; ++ i) {
        string s;
        vector<int> b(4);
        cin >> s; b[0] = s[0] - '0'; b[1] = s[1] - '0';
        cin >> s; b[2] = s[0] - '0'; b[3] = s[1] - '0';
        int u = b[0] * 8 + b[1] * 4 + b[2] * 2 + b[3] * 1;
        ans = min(ans, dp[(1 << 16) - 1][get(u)]);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    for (int i{}; i < 4; ++ i) cin >> a[i];
    for (int u{}; u < 16; ++ u) {
        for (int j{}; j < 4; ++ j) g[get(u)][get(u ^ (1ll << j))] = g[get(u ^ (1ll << j))][get(u)] = a[0];
        g[get(u)][get(u ^ 12)] = g[get(u ^ 12)][get(u)] = g[get(u)][get(u ^ 3)] = g[get(u ^ 3)][get(u)] = a[1];
        g[get(u)][get(u ^ 10)] = g[get(u ^ 10)][get(u)] = g[get(u)][get(u ^ 5)] = g[get(u ^ 5)][get(u)] = a[2];
        g[get(u)][get(u ^ 15)] = g[get(u ^ 15)][get(u)] = a[3];
    }
    for (int i{}; i < 16; ++ i)
        for (int j{}; j < 16; ++ j)
            for (int k{}; k < 16; ++ k) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    dp[1][0] = 0;
    for (int S = 1; S < (1 << 16); ++ S)
        for (int j{}; j < 16; ++ j)
            if ((S >> j) & 1)
                for (int k{}; k < 16; ++ k)
                    if ((S ^ (1 << j)) >> k & 1) dp[S][j] = min(dp[S][j], dp[S ^ (1 << j)][k] + g[k][j]);
    while(_ --) solve();
    return 0;
}