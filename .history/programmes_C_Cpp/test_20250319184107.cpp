#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector g(n + 1, vector<int> (m + 1, 0));
    vector vis = g;
    int sx, sy;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            cin >> g[i][j];
            if (g[i][j] == 2) sx = i, sy = j;
        }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}