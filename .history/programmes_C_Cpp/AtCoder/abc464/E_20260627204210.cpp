#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int H, W, Q; cin >> H >> W >> Q;
    int offset{W + 10};
    vector<int> dp((H + 10) * offset, 0);
    vector<char> S(Q + 1, 'A');
    for (int i{1}; i <= Q; ++ i) {
        int R, C; cin >> R >> C;
        char X; cin >> X;
        S[i] = X;
        dp[R * offset + C] = i;
    }
    for (int r{H}; r; -- r)
        for (int c{W}; c; -- c) {
            int cur{dp[r * offset + c]};
            int down{dp[(r + 1) * offset + c]}, rght{dp[r * offset + c + 1]};
            if (down > cur) cur = down;
            if (rght > cur) cur = rght;
            dp[r * offset + c] = cur;
    }
    string ans(W, ' ');
    for (int r{1}; r <= H; ++ r) {
        for (int c{1}; c <= W; ++ c) ans[c - 1] = S[dp[r * offset + c]];
        cout << ans << "\n";    
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}