#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
constexpr int MOD = 998244353;
int fac[N] = {1, 1}, inv[N];
int fp(int a, int x) {
    int r = 1;
    while (x) {
        a = a * a % MOD;
        if (x) r = r * a % MOD;
        x >>= 1;
    }
    return r;
}
void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    vector b = a;
    sort(b.begin(), b.end());

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (int i = 2; i < N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = fp(fac[N - 1], MOD - 2);
    for (int i = N - 2; ~i; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}