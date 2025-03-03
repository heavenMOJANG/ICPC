#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string path; cin >> path;
    vector g(n, vector<int>(m));
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) cin >> g[i][j];
    int x{}, y{};
    for (char ch : path) {
        if (ch == 'D') {
            int sum{};
            for (int i = 0; i < m; ++ i) sum += g[x][i];
            g[x][y] = -sum;
            x ++;
        } else {
            int sum{};
            for (int i = 0; i < n; ++ i) sum += g[i][y];
            g[x][y] = -sum;
            y ++;
        }
    }
    int sum{};
    for (int i = 0; i < m; ++ i) sum += g[n - 1][i];
    g[n - 1][m - 1] = -sum;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) cout << g[i][j] << " \n"[j == m - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}