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
int fastPow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a;
        a = a * a;
        x >>= 1;
    }
    return res;
}
void solve() {
    int x, y; cin >> x >> y;
    if (x % y == 0) {cout << y << " " << x / y << "\n"; return;}
    int tx = x, ty = y;
    map<int, int> mpx, mpy;
    int p = 0;
    while (tx != 1) {
        int k = 0;
        while (tx % primes[p] == 0) tx /= primes[p], k++;
        if (k) mpx[primes[p]] = k;
        p ++;
    }
    p = 0;
    while (ty != 1) {
        int k = 0;
        while (ty % primes[p] == 0) ty /= primes[p], k++;
        if (k) mpy[primes[p]] = k;
        p ++;
    }
    int n = 1;
    for (auto [a, b] : mpy)
        if (b > mpx[a]) n *= fastPow(a, b - mpx[a]);
    if (n % 2 == 0) n >>= 1;
    cout << y << " " << (2 * n * x) / y << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}