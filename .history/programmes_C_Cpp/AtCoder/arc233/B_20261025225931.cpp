//template by Luogu P2522 https://www.luogu.com.cn/problem/P2522
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
    int N, n, m; cin >> N >> n >> m;
    int K{N / m};
    if (n == 0) { cout << (pre[K] + 1) % MOD << "\n"; return; }
    vector<int> A(K + 1);
    for (int i : views::iota(1, K + 1)) A[i] = min(i - 1, (N - i * m) / n);
    int cnt{};
    for (int d : views::iota(1, K + 1)) {
        if (mu[d] == 0) continue;
        int cur{};
        for (int i : views::iota(d, K + 1) | views::stride(d)) cur += A[i] / d;
        cnt += mu[d] * cur;
    }
    cout << (1 + (n + m <= N) + 2 * cnt) % MOD << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    init();
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}