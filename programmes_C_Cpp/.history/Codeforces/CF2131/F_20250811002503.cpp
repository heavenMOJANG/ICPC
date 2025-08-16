#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<int> cnt(2 * n + 10, 0), cnt0(2 * n + 10, 0), cnt1(2 * n + 10, 0);
    int c0{};
    for (int y = 1; y <= n; ++ y) {
        if (b[y - 1] == '0') c0 ++;
        int c1 = y - c0, d = y - 2 * c0, idx = d + n;
        cnt[idx] ++;
        cnt0[idx] += c0;
        cnt1[idx] += c1;
    }
    vector<int> prec(2 * n + 10, 0), pre0(2 * n + 10, 0), pre1(2 * n + 10, 0);
    prec[0] = cnt[0]; pre0[0] = cnt0[0]; pre1[0] = cnt1[0];
    for (int i = 1; i <= 2 * n + 1; ++ i) {
        prec[i] = prec[i - 1] + cnt[i];
        pre0[i] = pre0[i - 1] + cnt0[i];
        pre1[i] = pre1[i - 1] + cnt1[i];
    }
    int sumc = prec[n << 1 | 1], sum0 = pre0[n << 1 | 1], sum1 = pre1[n << 1 | 1], ans{};
    int d0{};
    for (int x = 1; x <= n; ++ x) {
        if (a[x - 1] == '0') d0 ++;
        int d1 = x - d0, d = 2 * d0 - x, idx = d + n, res{};
        if (idx) res += prec[idx - 1] * d1 + pre1[idx - 1];
        res += (sumc - (idx ? prec[idx - 1] : 0ll)) * d0 + (sum0 - (idx ? pre0[idx - 1] : 0ll));
        ans += res;
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