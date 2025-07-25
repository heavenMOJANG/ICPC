#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string g[n + 1];
    vector a(n + 1, vector<char>(n + 1)); 
    for (int i = 1; i <= n; ++ i) cin >> g[i], g[i] = " " + g[i];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            int d = min({i, j, n - i + 1, n - j + 1});
            switch (d % 4) {
                case 0: a[i][j] = g[i][j]; break;
                case 1: a[j][n - i + 1] = g[i][j]; break;
                case 2: a[n - i + 1][n - j + 1] = g[i][j]; break;
                case 3: a[n - j + 1][n - i + 1] = g[i][j]; break;
            }
        }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) cout << a[i][j];
        cout << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}