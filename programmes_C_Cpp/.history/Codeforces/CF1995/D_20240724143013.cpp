#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, c, k; cin >> n >> c >> k;
    string s; cin >> s;
    int cnt[26]{}, state = 0;
    vector<int> dp(1 << c);
    dp[1 << (s.back() - 'A')] = 1;
    for (int i = 0, j = -1; i + k - 1 < n; ++ i) {
        if (i - 1 >= 0) {
            int x = s[i - 1] - 'A';
            if (-- cnt[x] == 0) {
                state ^= 1ll << x;
            }
        }
        while (j + 1 <= i + k - 1) {
            int x = s[++ j] - 'A';
            if (++ cnt[x] == 1) {
                state ^= 1ll << x;
            }
        }
        dp[state] = 1;
    }
    for (int i = 0; i < c; ++ i) 
        for (int j = 0; j < (1ll << c); ++ j)
            if ((j >> i) & 1) dp[j] |= dp[j ^ (1ll << i)];
    const int mask = (1ll << c) - 1;
    int ans = inf;
    for (int i = 0; i < c; ++ i)
        if (!dp[i]) ans = min(ans, (int)__builtin_popcount(mask ^ i));
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}