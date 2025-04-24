#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
int primes[N], notPrime[N], idx;
void getPrimes() {
    for (int i = 2; i < N; ++ i) {
        if (!notPrime[i]) primes[idx ++] = i;
        for (int j{}; j < idx && i * primes[j] < N; ++ j) {
            notPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a, b;
    for (int j{}; j < m; ++ j) b.emplace_back(primes[j]);
    int cnt{};
    while (a.size() <= n) {

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