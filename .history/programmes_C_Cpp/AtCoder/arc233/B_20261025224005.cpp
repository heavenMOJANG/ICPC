#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int MAXN = 1e6 + 10;
int mu[MAXN], phi[MAXN], pre[MAXN];
bool isPrime[MAXN];
vector<int> primes;
void init() {
    mu[1] = phi[1] = 1;
    for (int i : views::iota(2, MAXN)) {
        if (!isPrime[i]) {
            primes.emplace_back(i);
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for (int p : primes) {
            if (p * i >= MAXN) break;
            isPrime[p * i] = true;
            if (i % p == 0) { mu[p * i] = 0; phi[p * i] = phi[i] * p; break; }
            mu[p * i] = -mu[i];
            phi[p * i] = phi[i] * (p - 1);
        }
    }
    for (int i : views::iota(1, MAXN)) pre[i] = pre[i - 1] + phi[i];
}
void solve() {
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}