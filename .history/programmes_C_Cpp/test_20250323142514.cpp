#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int idx, primes[N], isPrime[N];
void getPrimes() {
    for (int i = 2; i < N; ++ i) {
        if (!isPrime[i]) primes[idx ++] = i;
        for (int j = 0; j < idx && i * primes[j] < N; ++ j) {
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
int ok;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    vector<int> c(n + 1);
    int cnt{};
    for (int i = 1; i <= n; ++ i) {
        a[i] += a[i - 1];
        c[i] = (a[i] + i - 1) / i;
        if (!isPrime[c[i]]) cnt ++;
        if (cnt >= i / 3 - 1) ok ++;
    }
    if (ok == n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    getPrimes();
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}