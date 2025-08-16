#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
struct seg { int l, r, w; };
void solve() {
    int n, m; cin >> n >> m;
    int B = 1;
    auto qpow = [&](int x, int y = MOD - 2) {
        int res = 1;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    };
    vector<seg> v;
    for (int i{}; i < n; ++ i) {
        int l, r, p, q; cin >> l >> r >> p >> q;
        int inv = qpow(q);
        (B *= ((q - p) % MOD + MOD) % MOD * inv % MOD) %= MOD;
        inv = qpow(((q - p) % MOD + MOD) % MOD);
        int A = p % MOD * inv % MOD;
        v.emplace_back(l, r, A);
    }
    sort(v.begin(), v.end(), [&](const seg& x, const seg& y) {
        return x.r < y.r;
    });
    vector<int> dp(m + 1);
    dp[0] = 1;
    int pos{};
    for (int i = 1; i <= m; ++ i) {
        int sig{};
        while (pos < n && v[pos].r <= i) {
            auto [l, r, w] = v[pos ++];
            (sig += w * dp[l - 1] % MOD) %= MOD;
        }
        dp[i] = sig;
    }
    int ans = B * dp[m] % MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}