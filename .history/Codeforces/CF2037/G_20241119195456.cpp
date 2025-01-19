#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
constexpr int MAXN = 1e6 + 10;
constexpr int MOD = 998244353;
int n, primes[MAXN], isPrime[MAXN], idx, mu[MAXN];
int f[N], g[N];
void eulerSieve(int x = MAXN - 1) {
    for (int i = 2; i <= x; ++ i) {
        if (!isPrime[i]) primes[idx ++] = i, mu[i] = -1;
        for (int j = 0; j < idx && i * primes[j] <= x; ++ j) {
            isPrime[i * primes[j]] = 1;
            if (!(i % primes[j])) break;
            mu[i * primes[j]] = -mu[i];
        }
    }
}
void solve() {
    eulerSieve();
    cin >> n;
    f[1] = 1;
    for (int i = 1, x; i <= n; ++ i) {
        cin >> x;
        for (int j = 1; j * j <= x; ++ j)
            if (!(x % j)) {
                f[i] = (f[i] - mu[j] * g[j]) % MOD;
                if (j * j < x) f[i] = (f[i] - mu[x / j] * g[x / j]) % MOD;
            }
        for (int j = 1; j * j <= x; ++ j)
            if (!(x % j)) {
                g[j] = (g[j] + f[i]) % MOD;
                if (j * j < x) g[x / j] = (g[x / j] + f[i]) % MOD;
            }
    }
    cout << (f[n] + MOD) % MOD << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}