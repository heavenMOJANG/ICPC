#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
constexpr int MOD = 998244353;
int n, primes[N], isPrime[N], idx, flag[N];
void eulerSieve(int x = n) {
    for (int i = 2; i <= x; ++ i) {
        if (!isPrime[i]) primes[idx ++] = i, flag[i] = -1;
        for (int j = 0; j < idx && i * primes[j] <= x; ++ j) {
            isPrime[i * primes[j]] = 1;
            if (!(i % primes[j])) break;
            flag[i * primes[j]] = -flag[i];
        }
    }
}
void solve() {

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}