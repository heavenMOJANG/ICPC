#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int to(int x, int s) { return x * 1024 + s; }
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[1 << 20];
    for (int i{}; i < m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        for (int j{}; j < 1024; ++ j) g[to(u, j)].emplace_back(to(v, j ^ w));
    }
    vector dis(1025, vector<int> (1024, -1));
    queue<int> q;
    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}