#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector g(n, vector<int>(n));
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j) cin >> g[i][j];
    int ans{};
    for (int i = 0; i < n; ++ i) {
        int minn = g[0][i];
        int x{}, y = i;
        while (x < n && y < n) minn = min(minn, g[x][y]), x ++, y ++;
        if (minn < 0) ans += minn;
    }
    for (int j = 1; j < n; ++ j) {
        int minn = g[j][0];
        int x = j, y{};
        while (x < n && y < n) minn = min(minn, g[x][y]), x ++, y ++;
        if (minn < 0) ans += minn;
    }
    cout << -ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}