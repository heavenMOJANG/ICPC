#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e7 + 10;
constexpr int INF = 0x7fffffff;
int idx, primes[N], isPrime[N];
void getPrimes() {
    for (int i = 2; i < N; ++ i) {
        if (!isPrime[i]) primes[idx ++] = i;
        for (int j{}; j < idx && i * primes[j] < N; ++ j) {
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}