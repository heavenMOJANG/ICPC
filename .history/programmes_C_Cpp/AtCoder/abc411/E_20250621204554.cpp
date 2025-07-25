#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i{}; i < n; ++ i)
        for (int j{}; j < 6; ++ j) {
            int x; cin >> x;
            a.emplace_back(x, i);
        }
    sort(a.begin(), a.end());
    vector<int> fac(7, 0), inv(7, 0);
    fac[0] = 1;
    for (int i = 1; i < 7; ++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[6] = fastPow()
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}