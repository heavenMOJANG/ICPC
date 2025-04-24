#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a, b, vis(n * m, 0);
    for (int i = 1; i <= n * m; i += m) a.emplace_back(i % (n * m));
    for (int i = 1; i <= n * m; i += n) b.emplace_back(i % (n * m));
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) {
            int d = a[i] * b[j] % (n * m);
            if (vis[d]) { cout << "No\n"; return; }
            else vis[d] = 1;
        }
    cout << "Yes\n";
    for (int i{}; i < n; ++ i) cout << a[i] << " \n"[i == n - 1];
    for (int j{}; j < m; ++ j) cout << b[j] << " \n"[j == m - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}