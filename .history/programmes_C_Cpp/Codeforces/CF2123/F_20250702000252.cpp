#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> isPrime(n + 1, 1), primes;
    for (int i = 2; i <= n; ++ i) {
        if (isPrime[i]) primes.emplace_back(i);
        for (int j{}; j < primes.size() && i * primes[j] <= n; ++ j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }
    }
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}