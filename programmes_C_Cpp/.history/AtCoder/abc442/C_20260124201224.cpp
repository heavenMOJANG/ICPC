#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int C3(int n) {
    if (n < 3) return 0ll;
    return n * (n - 1) * (n - 2) / 6;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> d(n + 1, 0);
    for (int i{}; i < m; ++ i) {
        int u, v; cin >> u >> v;
        d[u] ++, d[v] ++;
    }
    for (int i = 1; i <= n; ++ i) cout << C3(n - 1 - d[i]) << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}