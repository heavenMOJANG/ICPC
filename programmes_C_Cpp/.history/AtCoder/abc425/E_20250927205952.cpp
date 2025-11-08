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
    int n; cin >> n;
    vector<int> c(n);
    int tot{};
    for (auto && x : c) cin >> x, tot += x;
    if (!tot) { cout << "1\n"; return; }
    vector<int> cnt(tot + 1, 0);
    for (int x : c) if (x <= tot) cnt[x] ++;
    vector<int> suf(tot + 2, 0);
    for (int i = tot; i >= 1; -- i) suf[i] = suf[i + 1] + cnt[i];
    auto qpow = [&](int a, int x) {
        int f = 1;
        while (x) {
            if (x & 1) f = f * a % MOD;
            a = a * a % MOD;
            x >>= 1;
        }
        return f;
    };
    int ans = 1;
    for (int p : primes) {
        if (p > tot) break;
        int exp{}, pp = p;
        while (pp <= tot) {
            int s{};
            for (int j = pp; j <= tot; j += pp) s += suf[j];
            exp += tot / pp - s;
            if (pp > tot / p) break;
            pp *= p;
        }
        if (exp) ans = (ans * qpow(p, exp)) % MOD;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _ >> MOD;
    euler();
    while(_ --) solve();
    return 0;
}