#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
constexpr int N = 2e5 + 10;
struct Edge {
    int to, nxt, val;
}e[];
struct Node {
    int id, d, dir;
    bool operator < (const Node &rhs) const {
        return d > rhs.d;
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector t(n + 1, vector<int>(m + 1)), d = t;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> t[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> d[i][j];
    vector<Edge> e(n * m + 10 << 2);
    vector<int> head(n * m + 10);
    fill(head.begin(), head.end(), -1);
    auto addEdge = [&](int u, int v, int w) {
        e[]
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}