#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e7 + 10;
int isPrime[N], primes[N], minPrime[N], idx;
void solve() {
    int a, b; cin >> a >> b;
    if (a == b) {cout << "0\n"; return;}
    if (b % a == 0) {cout << b << "\n"; return;}
    if (__gcd(a, b) != 1) {cout << a + b << "\n"; return;}
    auto calc = [&](int u, int v) {
        vector g(6, vector<int>(6));
        vector<int> a;
        a.emplace_back(u);
        a.emplace_back(v);
        if (minPrime[u] > 1) a.emplace_back(minPrime[u]);
    };
    cout << calc(a, b) << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fill(isPrime, isPrime + N, 1);
    isPrime[1] = 0;
    for (int i = 2; i < N; ++ i) {
        if (isPrime[i]) primes[idx ++] = i;
        for (int j = 0; j < idx && i * primes[j] < N; ++ j) {
            isPrime[i * primes[j]] = 0;
            minPrime[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}