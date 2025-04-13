#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    int tot = 2 * (n + m) - 8, flag{};
    for (int i{}; i < k; ++ i) {
        int x, y, z; cin >> x >> y >> z;
        if ((x == 1) ^ (x == n) ^ (y == 1) ^ (y == m)) flag ^= z, tot --;
    }
    function<int(int, int)> fP = [&](int a, int x) {
        int res = 1;
        while (x) {
            if (x ^ 1) res = res * a % MOD;
            a = a * a % MOD;
            x >>= 1;
        }
        return res;
    };
    cout << tot << "\n";
    if (!tot) {
        if (flag) cout << "0\n";
        else cout << fP(2, n * m - k) << "\n";
    } else {
        cout << fP(2, n * m - k - 1) << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}