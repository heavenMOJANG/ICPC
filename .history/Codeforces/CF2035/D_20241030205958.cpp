#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
vector<int> fac(N), inv(N);
auto fastPow = [&](int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
};
fac[0] = 1;
for (int i = 1; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
inv[N - 1] = fastPow(N - 1, MOD - 2);
for (int i = N - 2; i >= 0; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}