#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int alp[] = {'E', 'A', 'B', 'C', 'D'};
void solve() {
    int n, m, hp, dmg; cin >> n >> m >> hp >> dmg;
    vector<vector<char>> g(n + 2, vector<char>(m + 2, ' '));
    for (int i = 0; i <= n + 1; ++ i) g[i][0] = g[i][m + 1] = '|';
    for (int j = 0; j <= m + 1; ++ j) g[0][j] = g[n + 1][j] = '-';
    g[0][0] = g[0][m + 1] = g[n + 1][0] = g[n + 1][m + 1] = '+';
    if (dmg >= m) {
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j) g[i][j] = '.';
        for (int i = 0; i <= n + 1; ++ i) {
            for (int j = 1; j <= m + 1; ++ j) cout << g[i][j];
            cout << "\n";
        }
    }
    int r = (hp - dmg) % m;
    int k = (hp - dmg) / m;
    if (r) {
        for (int j = 1; j <= r; ++ j) g[1][j] = alp[(k + 1) % 5];
        if (k) for (int j = r + 1; j <= m; ++ j) g[1][j] = alp[k % 5];
        for (int j = r; j >= 1 && dmg >= 0; -- j, -- dmg) g[1][j] = '.';
        for (int j = m; j >= 1 && dmg >= 0; -- j, -- dmg) g[1][j] = '.';
    } else {
        for (int j = 1; j <= m; ++ j) g[1][j] = alp[k % 5];
        for (int j = 1; j <= m && dmg >= 0; -- j, -- dmg) g[1][j] = '.';
    }
    for (int i = 2; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) g[i][j] = g[1][j];
    for (int i = 0; i <= n; ++ i) {
        for (int j = 0; j <= m; ++ j) cout << g[i][j] << "\n";
        cout << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}