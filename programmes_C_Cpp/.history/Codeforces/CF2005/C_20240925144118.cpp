#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
map<char, int> id, vis;
void solve() {
    int n, m; cin >> n >> m;
    vector dp(n + 1, vector<int>(6, -INF));
    dp[0][0] = 0;
    vector<int> sum(5), len(5);
    function<void(string)> init = [&](string s) {
        for (int i = 0; i <= 4; ++ i) sum[i] = 0, len[i] = i;
        for (int i = 1; i <= m; ++ i) {
            if (vis[s[i]]) {
                for ()
            }
        }
    };
    for (int i = 1; i <= n; ++ i) {
        string s; cin >> s;
        s = " " + s;

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}