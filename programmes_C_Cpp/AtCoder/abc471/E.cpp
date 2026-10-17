#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, K; cin >> N >> K;
    int sum{}, sq{};
    for (int i : views::iota(0, N)) {
        int A; cin >> A;
        A %= MOD;
        (sum += A) %= MOD;
        (sq += A * A % MOD) %= MOD;
    }
    vector<int> fac(N + 1), inv(N + 1);
    fac[0] = 1;
    for (int i : views::iota(1, N + 1)) fac[i] = fac[i - 1] * i % MOD;
    auto qpow = [&](int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) (res *= a) %= MOD;
            (a *= a) %= MOD;
            b >>= 1;
        }
        return res;
    };
    inv[N] = qpow(fac[N], MOD - 2);
    for (int i : views::iota(1, N + 1)) inv[N - i] = inv[N - i + 1] * (N - i + 1) % MOD;
    auto C = [&](int n, int m) {
        if (n < m || m < 0) return 0LL;
        return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    int c1{C(N - 1, K - 1)}, c2{C(N - 2, K - 2)};
    int d{(sum * sum % MOD - sq + MOD) % MOD};
    cout << (c1 * sq % MOD + c2 * d % MOD) % MOD << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}