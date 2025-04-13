#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string s[n + 1];
    for (int i = 1; i <= n; ++ i) cin >> s[i], s[i] = " " + s[i];
    int ok = 1;
    vector row(n + 1, vector<int>(m + 1, 0)), col = row;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            if (s[i][j] == '1') {
                row[i][j] = row[i][j - 1] + 1;
                col[i][j] = col[i - 1][j] + 1;
            } else {
                row[i][j] = row[i][j - 1];
                col[i][j] = col[i - 1][j];
            }
        }
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            if (s[i][j] == '1') {
                if (row[i][j - 1] - row[i][0] == j - 1) continue;
                if (col[i - 1][j] - col[0][j] == i - 1) continue;
            }
        }
    cout << (ok ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}