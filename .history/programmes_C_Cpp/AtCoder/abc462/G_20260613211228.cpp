#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int dp[2][3][201];
void solve() {
    string S; cin >> S;
    int N = S.size(), K; cin >> K;
    for (int s{}; s < 3; ++ s)
        for (int d{}; d <= 200; ++ d) dp[0][s][d] = INF;
    dp[0][0][30] = 0;
    for (int i{}; i < N; ++ i) {
        int cur = i & 1, nxt = (i + 1) & 1;
        for (int s{}; s < 3; ++ s)
            for (int d{}; d <= 200; ++ d) dp[nxt][s][d] = INF;
        int f = (i >= 2 && S[i-2] == 'A' && S[i-1] == 'B' && S[i] == 'C') ? 1ll : 0ll;
        for (int s{}; s < 3; ++ s)
            for (int d{}; d <= 200; ++ d) {
                if (dp[cur][s][d] == INF) continue;
                for (int c{}; c < 3; ++ c) {
                    int ss = (c == 0) ? 1ll : (c == 1 && s == 1) ? 2ll : 0ll;
                    int dd = d + (c == 2 && s == 2) - f;
                    int w = (c + 'A' == S[i]) ? 0ll : 1ll;
                    if (0 <= dd && dd <= 60) dp[nxt][ss][dd] = min(dp[nxt][ss][dd], dp[cur][s][d] + w);
                }
                if (S[i] != 'A' && S[i] != 'B' && S[i] != 'C') {
                    int dd = d - f;
                    if (0 <= dd && dd <= 60) dp[nxt][0][dd] = min(dp[nxt][0][dd], dp[cur][s][d]);
                }
            }
    }
    int tar = K + 30;
    int ans = (tar <= 60) ? min({dp[N & 1][0][tar], dp[N & 1][1][tar], dp[N & 1][2][tar]}) : INF;
    cout << (ans == INF ? -1ll : ans) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}
