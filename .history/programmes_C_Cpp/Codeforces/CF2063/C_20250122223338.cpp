#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int id, d;
    bool operator < (const Node & b) const { return d > b.d; }
};
void solve() {
    int n; cin >> n;
    vector<Node> d(n);
    vector<int> g[n];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
        u --, v --;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        d[u].id = u; d[u].d ++;
        d[v].id = v; d[v].d ++;
    }
    if (n == 2) { cout << "0\n"; return; }
    sort(d.begin(), d.end());
    int flag{};
    for (auto v : g[d[0].id]) if (v == d[1].id) { flag = 1; break; }
    cout << d[0].d + d[1].d - flag << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}