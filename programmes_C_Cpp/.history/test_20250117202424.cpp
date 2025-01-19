#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), cnt(n + 1);
    auto cal = [&](int x) {
        int res{};
        while (x % 5 == 0) x /= 5, res ++;
        return res;
    };
    auto fastPow = [&](int a, int x) {
        int res = 1;
        while (x) {
            if (x & 1) res = res * a % MOD;
            a = a * a % MOD;
            x >>= 1;
        }
        return res;
    };
    for (int i = 1; i <= n; ++ i) cin >> a[i], cnt[i] = cal(a[i]);
    int sum{}, cur = 1, cnt5{};
    for (int i = 1; i <= n; ++ i) {
        (cur *= a[i]) %= MOD;
        cnt5 += cnt[i];
        while (cnt5 >= 2) {
            (cur *= fastPow(25, MOD - 2)) %= MOD;
            cnt5 -= 2;
        }
        (sum += cur) %= MOD;
    }
    cout << sum << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}