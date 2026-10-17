#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int inv2 = 499122177;
constexpr int MOD = 998244353;
constexpr int MAXN = 2e5 + 10;
struct Query { int n, m, idx, x; };
int fac[MAXN]{1}, inv[MAXN]{1}, p2[MAXN]{1};
int qpow(int a, int x) {
    int res{1};
    a %= MOD;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
};
int C(int n, int m) {
    if (!~m || m > n) return 0ll;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve() {

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (int i{1}; i < MAXN; ++ i) {
        fac[i] = fac[i - 1] * i % MOD;
        p2[i] = p2[i - 1] * inv2 % MOD;
    }
    inv[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);
    for (int i{MAXN - 2}; i; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    int T; cin >> T;
    vector<Query> q;
    vector<int> ans(T);
    for (int i{}; i < T; ++ i) {
        int N, X; cin >> N >> X;
        X = abs(X);
        if (X >= N) ans[i] = X % MOD;
        else {
            int M = (N + X) / 2;
            q.emplace_back(N, M, i, X);
        }
    }
    int b{max(1ll, (int)2e5 / (int)sqrt(max(1ll, (int)q.size())))};

    return 0;
}