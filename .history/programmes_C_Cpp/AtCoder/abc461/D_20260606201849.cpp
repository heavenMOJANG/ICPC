#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int H, W, K; cin >> H >> W >> K;
    vector<string> S(H);
    for (auto && s : S) cin >> s;
    vector<vector<int>> pre(H + 1, vector<int>(W + 1, 0));
    for (int i{1}; i <= H; ++ i)
        for (int j{1}; j <= W; ++ j)
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (S[i - 1][j - 1] - 48);
    int ans{};
    vector<int> cnt(H * W + 1, 0);
    for (int r1{1}; r1 <= H; ++ r1)
        for (int r2{r1}; r2 <= H; ++ r2) {
            cnt[0] = 1;
            for (int c{1}; c <= W; ++ c) {
                int d = pre[r2][c] - pre[r1 - 1][c];
                if (d >= K) ans += cnt[d - K];
                cnt[d] ++;
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