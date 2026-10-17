#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    if (S[0] == 'x' || S[N - 1] == 'x') { cout << "0\n"; return; }
    vector<int> dp(N + 1), ndp(N + 1);
    dp[1] = 1;
    for (int i : views::iota(1, N)) {
        ranges::fill(ndp, 0);
        int res{dp[i]};
        for (int j : views::iota(i + 1, N + 1)) {
            ndp[j] = ((j - i) * dp[j] + 2 * res) % MOD;
            (res += dp[j]) %= MOD;
        }
        if (S[i] == 'o') fill(ndp.begin() + min(i + 2, N + 1), ndp.end(), 0);
        else ndp[i + 1] = 0;
        dp.swap(ndp);
    }
    cout << dp[N] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}