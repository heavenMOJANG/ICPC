#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6;
int idx, primes[N], isPrime[N + 1];
void getPrimes() {
    fill(isPrime, isPrime + 1 + N, 1);
    isPrime[1] = 0;
    for (int i = 2; i <= N; ++ i) {
        if (isPrime[i]) primes[idx ++] = i;
        for (int j = 0; j < idx && i * primes[j] <= N; ++ j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int x, y; cin >> x >> y;
    int tx = x, ty = y;
    map<int, int> mpx, mpy;
    int p = 0;
    while (tx != 1) {
        int k = 0;
        while (tx % primes[p] == 0) tx /= primes[p], k++;
        mpy[primes[p]] = k;
        p ++;
    }
    while (ty != 1) {

    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}