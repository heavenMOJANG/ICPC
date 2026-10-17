#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int dp[2][3][61];
void solve() {
    string S; cin >> S;
    int N = S.size(), K; cin >> K;
    for (int s{}; s < 3; ++ s)
        for (int d{}; d <= 60; ++ d) dp[0][s][d] = INF;
    dp[0][0][30] = 0;
    for (int i{}; i < N; ++ i) {
        int cur = i & 1, nxt = (i + 1) & 1;
        for (int s{}; s < 3; ++ s)
            for (int d{}; d <= 60; ++ d) dp[nxt][s][d] = INF;
        int f = (i >= 2 && S[i-2] == 'A' && S[i-1] == 'B' && S[i] == 'C') ? 1 : 0;
        for (int s{}; s < 3; ++ s)
            for (int d{}; d <= 60; ++ d) {
                if (dp[cur][s][d] == INF) continue;
                for (int c{}; c < 3; ++c) {
                    int ns = (c == 0) ? 1 : (c == 1 && s == 1) ? 2 : 0;
                    int nd = d + (c == 2 && s == 2) - f;
                    int cost = (c + 'A' == S[i]) ? 0 : 1;
                    if (nd >= 0 && nd <= 60) dp[nxt][ns][nd] = min(dp[nxt][ns][nd], dp[cur][s][d] + cost);
                }
                
                // 如果原字符既不是 A 也不是 B 或 C，我们可以选择保留它（0成本打断匹配）
                if (S[i] != 'A' && S[i] != 'B' && S[i] != 'C') {
                    int nd = d - f;
                    if (nd >= 0 && nd <= 60) 
                        dp[nxt][0][nd] = min(dp[nxt][0][nd], dp[cur][s][d]);
                }
            }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
