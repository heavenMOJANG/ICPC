#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
map<char, int> id{{'n', 1}, {'a', 2}, {'r', 3}, {'e', 4}, {'k', 5}}, vis{{'n', 1}, {'a', 2}, {'r', 3}, {'e', 4}, {'k', 5}};
void solve() {
    int n, m; cin >> n >> m;
    vector dp(n + 1, vector<int>(6, -INF));
    dp[0][0] = 0;
    vector<int> sum(5), len(5);
    function<void(string)> init = [&](string s) {
        for (int i = 0; i <= 4; ++ i) sum[i] = 0, len[i] = i;
        for (int i = 1; i <= m; ++ i) {
            if (vis[s[i]]) {
                for (int j = 0; j < 5; ++ j) {
                    if (id[s[i]] == len[j] + 1) {
                        len[j] ++;
                        if (len[j] == 5) sum[j] += 5, len[j] = 0;
                    } else sum[j] --;
                }
            }
        }
    };
    for (int i = 1; i <= n; ++ i) {
        string s; cin >> s;
        s = " " + s;
        init(s);
        for (int j = 0; j < 5; ++ j) dp[i][j] = dp[i - 1][j];
        for (int j = 0; j < 5; ++ j) dp[i][len[j]] = max(dp[i][len[j]], dp[i - 1][j] + sum[j]);

    }
    int ans = 0;
    for (int i = 0; i < 5; ++ i) ans = max(ans, dp[n][i] - i);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}