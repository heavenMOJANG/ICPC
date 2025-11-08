#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    vector<int> dp = {1, 1};
    for (int i{}; i < n - 1; ++ i) {
        vector<int> ndp = {0, 0};
        for (int j{}; j < 2; ++ j) {
            for (int k{}; k < 2; ++ k) {
                if (a[i] == b[i] && j != k) continue;
                if (a[i] != b[i] && a[i] == a[i + 1] && j != k) continue;
                if (a[i] != b[i] && b[i] == b[i + 1] && j == k) continue;
                ndp[k] = (ndp[k] + dp[j]) % MOD;
            }
        }
        dp = ndp;
    }
    cout << (dp[0] + dp[1]) % MOD << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}