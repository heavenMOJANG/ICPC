#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector a(n + 1, vector<int> (m + 1));
    cout << "YES\n";
    int idx = 1;
    if (n == 1) { for (int j = 1; j <= m; ++ j) cout << idx ++ << " \n"[j == m]; return; }
    if (m == 1) { for (int i = 1; i <= n; ++ i) cout << idx ++ << " \n"[i == n]; return; }
    if (n < m) {
        if (m & 1) {
            for (int i = 1; i <= n; ++ i) {
                if (i & 1) {
                    a[i][1] = idx ++;
                    for (int j = m; j >= 3; -- j) a[i][j] = idx ++;
                    a[i][2] = idx ++;
                } else for (int j = m; j >= 1; -- j) a[i][j] = idx ++;
            }
        } else for (int i = 1; i <= n; ++ i) for (int j = m; j >= 1; -- j) a[i][j] = idx ++;
    } else {
        if (n & 1) {
            for (int j = 1; j <= m; ++ j) {
                if (j & 1) {
                    a[1][j] = idx ++;
                    for (int i = n; i >= 3; -- i) a[i][j] = idx ++;
                    a[2][j] = idx ++;
                } else for (int i = n; i >= 1; -- i) a[i][j] = idx ++;
            }
        } else for (int j = 1; j <= m; ++ j) for (int i = 1; i <= n; ++ i) a[i][j] = idx ++;
    }
    for (int i = 1; i <= n; ++ i) for (int j = 1; j <= m; ++ j) cout << a[i][j] << " \n"[j == m];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}