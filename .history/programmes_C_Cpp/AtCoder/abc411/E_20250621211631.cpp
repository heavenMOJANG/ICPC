#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i{}; i < n; ++ i)
        for (int j{}; j < 6; ++ j) {
            int x; cin >> x;
            a.emplace_back(x, i);
        }
    sort(a.begin(), a.end());
    vector<int> fac(7, 0), inv(7, 0);
    auto fastPow = [&](int x, int y) {
        int res = 1;
        while (y --) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    };
    for (int i = 1; i < 7; ++ i) inv[i] = fastPow(i, MOD - 2);
    int inv6n = fastPow(inv[6], n);
    vector<int> cnt(n, 0);
    int cnt0, res = 1, F{}, ans{};
    for (int i{}; i < a.size(); ++ i) {
        int v = a[i].first, j = i;
        while (j < a.size() && a[j].first == v) {
            int d = a[i].second, pre = cnt[d], cur = pre + 1;
            cnt[d] = cur;
            if (pre == 0) {
                cnt0 --;
                res = (res * cur) % MOD;
            } else {
                res = res * cur % MOD * inv[pre] % MOD;
            }
            j ++;
        }
        int tmp{};
        if (cnt0 == 0) tmp = res * inv6n % MOD;
        int d = (tmp - F + MOD) % MOD;
        ans = (ans + v % MOD * d % MOD) % MOD;
        F = tmp;
        i = j;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}