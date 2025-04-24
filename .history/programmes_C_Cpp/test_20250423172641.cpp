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
    a.emplace_back(1);
    b.emplace_back(1);
    int cnt{};
    if (n > m) {
        for (int i = 2; i <= m; ++ i)  a.emplace_back(primes[cnt ++]), b.emplace_back(primes[cnt ++]);
        for (int i = m + 1; i <= n; ++ i) a.emplace_back(primes[cnt ++]);
    } else {
        for (int i = 2; i <= n; ++ i) b.emplace_back(primes[cnt ++]), a.emplace_back(primes[cnt ++]);
        for (int i = m + 1; i <= n; ++ i) b.emplace_back(primes[cnt ++]);
    }
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cout << a[i] * b[j] % (n * m) << " \n"[j == m];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}