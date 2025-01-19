#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    if (s[1] == 'R') dp[1][1] = 1;
    else if (s[1] == 'P') dp[1][2] = 1;
    else dp[1][0] = 1;
    for (int i = 2; i <= n; ++ i) {
        if (s[i] == 'R') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
            dp[i][]
        } else if (s[i] == 'P') {

        } else {

        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}