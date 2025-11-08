#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5010;
int MOD, notPrime[N];
vector<int> primes;
void euler() {
    for (int i = 2; i < N; ++ i) {
        if (!notPrime[i]) primes.emplace_back(i);
        for (auto p : primes) {
            if (i * p >= N) break;
            notPrime[i * p] = 1;
            if (i % p == 0) break;
        }
    }
}
void solve() {
    auto qpow = [&](int a, int x) {
        int f = 1;
        while (x) {
            if (x & 1) f = f * a % MOD;
            a = a * a % MOD;
            x >>= 1;
        }
        return f;
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _ >> MOD;
    euler();
    while(_ --) solve();
    return 0;
}