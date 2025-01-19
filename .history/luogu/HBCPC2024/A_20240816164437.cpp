#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e7 + 10;
int isPrime[N], primes[N], idx;
void solve() {
    int x, y; cin >> x >> y;
    int gcd = __gcd(x, y), lcm = x / gcd * y;
    if (gcd == 1) {cout << "1 " << lcm << "\n"; return;}
    int g = lcm / gcd, tmp = g;
    map<int, int> mp;
    int p = 0;
    while (g != 1) {
        int k = 0;
        while (g % primes[p] == 0) g /= primes[p], k ++;
        if (k) mp[primes[p]] = k;
    }

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fill(isPrime, isPrime + N, 1);
    isPrime[1] = 0;
    for (int i = 2; i < N; ++ i) {
        if (isPrime[i]) primes[idx ++] = i;
        for (int j = 0; j < idx && i * primes[j] < N; ++ j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}