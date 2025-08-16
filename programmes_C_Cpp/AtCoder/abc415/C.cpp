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
    for (int i{}; i < all; ++ i) {
        if (!dp[i]) continue;
        for (int j{}; j < n; ++ j)
            if ((i >> j & 1) == 0) {
                int nxt = i | (1 << j);
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