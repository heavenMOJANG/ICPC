#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e6 + 10;
int notPrime[N], primes[N], idx;
void getPrimes() {
    notPrime[1] = 1;
    for (int i = 2; i < N; ++ i) {
        if (!notPrime[i]) primes[idx ++] = i;
        for (int j{}; j < idx && primes[j] * i < N; ++ j) {
            notPrime[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) cout << (notPrime[n] ? "NO\n" : "YES\n");
    else {

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}