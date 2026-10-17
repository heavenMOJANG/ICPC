#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int inv2 = 499122177;
constexpr int MOD = 998244353;
void solve() {
    auto qpow = [&](int a, int x) -> int {
        int res{1};
        a %= MOD;
        while (x) {
            if (x & 1) res = res * a % MOD;
            a = a * a % MOD;
            x >>= 1;
        }
        return res;
    };
    auto inv = [&](int x) -> int { return qpow(x, MOD - 2); };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}