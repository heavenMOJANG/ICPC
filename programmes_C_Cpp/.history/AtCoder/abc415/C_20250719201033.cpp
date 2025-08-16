#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int all = (1 << n) - 1;
    vector<int> dp(all + 1, 0);
    dp[0] = 1;
    for (int mask{}; mask < all; ++ mask) {
        if (!dp[mask]) continue;
        for (int i{}; i < n; ++ i)
            if (mask >> i & 1 == 0) {
                int nxt = mask | (1 << i);
                if (s[nxt - 1] == '0') dp[nxt] = 1;
            }
    }
    cout << (dp[all] ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}