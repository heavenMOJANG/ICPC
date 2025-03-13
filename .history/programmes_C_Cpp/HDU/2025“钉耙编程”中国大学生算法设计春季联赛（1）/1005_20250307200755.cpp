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
struct Node {
    int d, x, y, dir;
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
    vector dis(n + 1, vector<vector<int>>(m + 1, vector<int> (4, 1e18)));
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}