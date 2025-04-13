#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 5e5 + 10;
int fac[N];
void solve() {
    vector<int> c(26);
    for (auto && x : c) cin >> x;
    int sum = accumulate(c.begin(), c.end(), 0ll);
    int odd = (sum + 1) / 2, even = sum / 2;
    for (int i{}; i < 26; ++ i)
        if (c[i] > odd && c[i] > even) { cout << "0\n"; return; }
    vector<int> dp(odd + 1, 0);
    dp[0] = 1;
    int ans = 
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}