#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, M; cin >> N >> M;
    int ans{}, l = 1, pwr = 1;
    for (int i{1}; i <= 19; ++ i) {
        if (l > N) break;
        int r = (i < 19 ? min(N, l * 10 - 1) : N);
        int cnty = (r - l + 1) % MOD;
        (pwr *= 10) %= M;
        int v = (pwr - 1 + M) % M;
        int g = __gcd(v, M), k = M / g;
        int cntx = N / k % MOD;
        (ans += cntx * cnty % MOD) %= MOD;
        if (i < 19) l *= 10;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}
