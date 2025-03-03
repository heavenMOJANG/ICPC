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
    if (n > m) {
        for (int i = 1; i <= n; ++ i) {
            if (m & 1) {
                if (i & 1) {
                    a[i][j]
                    a[i][j + 1]
                }
                else for (int j = m; j >= 1; -- j) a[i][j] = idx ++;
            }
            else {

            }
        }
    } else {

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}