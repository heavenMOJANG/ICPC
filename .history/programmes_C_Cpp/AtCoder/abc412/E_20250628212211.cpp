#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int L, R; cin >> L >> R;
    int n = R - L + 1, S = sqrt((long double)R);
    vector<int> isPrime(S + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= S; ++ i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) isPrime[j] = 0;
    }
    vector<int> primes;
    for (int i = 2; i <= S; ++ i) if (isPrime[i]) primes.emplace_back(i);
    vector<int> ip(n, 1);
    if (L == 1) ip[0] = 0;
    for (auto p : primes) {
        int s = max(p * p, (L + p - 1) / p * p);
        for (int x = s; x <= R; x += p) ip[x - L] = 0;
    }
    vector<int> f(n, 0);
    for (int i{}; i < n; ++ i) if (ip[i]) f[i] = 1;
    for (auto p : primes) {
        __int128 res = p * p;
        while (res <= R) {
            if (res >= L) f[(int)(res - L)] = 1;
            res *= p;
        }
    }
    int ans{};
    for (int i{}; i < n; ++ i) ans += f[i];
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}