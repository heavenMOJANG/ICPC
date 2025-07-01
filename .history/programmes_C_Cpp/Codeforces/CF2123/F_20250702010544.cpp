#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> f(n + 1, 0);
    for (int i = 2; i <= n; ++ i)
        if (!f[i])
            for (int j = i; j <= n; j += i) f[j] = i;
    vector<int> p(n + 1), g[n + 1];
    iota(p.begin(), p.end(), 0);
    for (int i = 2; i <= n; ++ i)
        if (f[i] <= n / 2) g[f[i]].emplace_back(i);
    for (int i = 2; i <= n / 2; ++ i) {
        auto &v = g[i];
        if (v.size() < 2) continue;
        for (int j{}; j < v.size(); ++ j) {
            int a = v[j], b = v[(j + 1) % v.size()];
            p[a] = b;
        }
    }
    for (int i = 1; i <= n; ++ i) cout << p[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}