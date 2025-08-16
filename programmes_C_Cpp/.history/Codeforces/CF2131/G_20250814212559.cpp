#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
int dp[31];
void solve() {
    int n, k; cin >> n >> k;
    vector<int> s(n);
    for (auto && x : s) cin >> x, x -= 1;
    sort(s.begin(), s.end());
    int ans = 1;
    function<int(int, int)> dfs = [&](int v, int k) {
        if (k == 0) return 1ll;
        int res = v + 1;
        k --;
        for (int i{}; i < min(v - 1, 30ll) + 1; ++ i)
            if (k >= 1 << i) res = res * dp[i] % MOD, k -= 1 << i;
            else { res = res * dfs(i, k) % MOD; break; }
        return res;
    };
    for (int v : s)
        if (v <= 30 && k >= 1 << v) k -= 1 << v, ans = ans * dp[v] % MOD;
        else { ans = ans * dfs(v, k) % MOD; break; }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    dp[0] = 1;
    for (int i = 1; i < 31; ++ i) {
        dp[i] = i + 1;
        for (int j{}; j < i; ++ j) dp[i] = dp[i] * dp[j] % MOD;
    }
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}