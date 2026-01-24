#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s[n];
    for (int i{}; i < n; ++ i) cin >> s[i];
    vector prew(n + 1, vector<int> (n + 1, 0)), sufb = prew;
    for (int i{}; i < n; ++ i) {
        for (int j = 1; j <= n; ++ j) prew[i][j] = prew[i][j - 1] + (s[i][j - 1] == '.');
        for (int j = n - 1; ~j; -- j) sufb[i][j] = sufb[i][j + 1] + (s[i][j] == '#');
    }
    vector<int> dp(n + 1, INF), ndp = dp;
    dp[0] = 0;
    for (int i{}; i <= n; ++ i) dp[i] = prew[0][i] + n - sufb[0][i];
    for (int i = 1; i < n; ++ i) {
        vector<int> sufm(n + 2, INF);
        sufm[n] = dp[n];
        for (int j = n - 1; ~j; -- j) sufm[j] = min(sufm[j + 1], dp[j]);
        for (int j{}; j <= n; ++ j) ndp[j] = sufm[j] + prew[i][j] + n - sufb[i][j];
        dp.swap(ndp);
    }
    cout << *min_element(dp.begin(), dp.end()) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}