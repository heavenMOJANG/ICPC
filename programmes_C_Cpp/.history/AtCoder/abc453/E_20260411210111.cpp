#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N; cin >> N;
    vector<int> diffA(N + 2, 0), diffB(N + 2, 0), diff(N + 2, 0);
    vector<int> fac(N + 1, 1), inv(N + 1);
    auto qpow = [&](int a, int x) {
        int res = 1;
        while (x) {
            if (x & 1) res = res * a % MOD;
            a = a * a % MOD;
            x >>= 1;
        }
        return res;
    };
    for (int i = 1; i <= N; ++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[N] = qpow(fac[N], MOD - 2);
    for (int i = N; i; -- i) inv[i - 1] = inv[i] * i %  MOD;
    auto C = [&](int n, int m) {
        if (m < 0 || m > n) return 0ll;
        return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    auto add = [&](vector<int>& d, int l, int r) {
        if (l > r) return;
        d[l] ++;
        d[r + 1] --;
    };
    for (int i{}; i < N; ++ i) {
        int L, R; cin >> L >> R;
        add(diffA, L, R);
        add(diffB, N - R, N - L);
        int l = max(L, N - R), r = min(R, N - L);
        add(diff, l, r);
    }
    int ans{}, cntA{}, cntB{}, cnt{};
    for (int x = 1; x < N; ++ x) {
        cntA += diffA[x];
        cntB += diffB[x];
        cnt += diff[x];
        int A = cntA - cnt, no = N - cntA - cntB + cnt;
        if (f == 0)
            (ans += C(cnt, x - A)) %= MOD;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}