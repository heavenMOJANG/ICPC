#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int L, R; cin >> L >> R;
    int n = floor(sqrt((long double)R)) + 1;
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; ++ i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) isPrime[j] = 0;
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++ i) if (isPrime[i]) primes.emplace_back(i);
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) pre[i] = pre[i - 1] + isPrime[i];
    auto sieve = [&](int l, int r) {
        int len = r - l + 1;
        vector<int> ip(len, 1);
        if (l == 1) ip[0] = 0;
        for (auto p : primes) {
            int s = max((l + p - 1) / p * p, p * p);
            for (int x = s; x <= r; x += p) ip[x - l] = 0;
        }
        int cnt{};
        for (auto x : ip) cnt += x;
        return cnt;
    };
    int d = sieve(L + 1, R);
    int maxk = (int)log2((long double)R) + 1;
    for (int k = 2; k <= maxk; ++ k) {
        int rR = krt(R, k), rL = krt(L, k);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}