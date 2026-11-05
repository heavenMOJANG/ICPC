#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int ROOT = 3;
int qpow(int a, int x) {
    int res = 1;
    while(x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
void ntt(vector<int>& a, bool inv) {
    int n{(int)a.size()};
    for (int i{1}, j{}; i < n; ++ i) {
        int bit{n >> 1};
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len{2}; len <= n; len <<= 1) {
        int wlen{qpow(ROOT, (MOD - 1) / len)};
        if (inv) wlen = qpow(wlen, MOD - 2);
        for (int i{}; i < n; i += len) {
            int w{1};
            for (int j : views::iota(0, len / 2)) {
                int u{a[i + j]}, v{a[i + j + len / 2] * w % MOD};
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                (w *= wlen) %= MOD;
            }
        }
    }
    if (inv) {
        int invN{qpow(n, MOD - 2)};
        for (int& x : a) (x *= invN) %= MOD;
    }
}
void solve() {
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}