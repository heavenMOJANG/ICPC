#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    map<int, int> ans;
    for (int i = 1; i * i <= m; ++ i)
        if (m % i == 0) ans[i] = ans[m / i] = 0;
    auto get = [&](int a, int x) { return (a % x + x) % x; };
    for (auto [x, y] : ans)
        for (int i = 1; i <= n; ++ i) ans[x] += get(a[i] - a[i - 1], x);
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int i, d; cin >> i >> d;
            for (auto [x, y] : ans) {
                ans[x] += get(d - a[i - 1], x) - get(a[i] - a[i - 1], x);
                if (i != n) ans[x] += (a[i + 1] - d, x) - get(a[i + 1] - a[i], x);
            }
            a[i] = d;
        } else {
            int k; cin >> k;
            cout << (ans[__gcd(k, m)] < m ? "YES\n" : "NO\n");
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}