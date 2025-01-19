#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector vis(n + 1, vector<int>(n + 1, 0));
    vector<pair<int, int>> S;
    string ans = "";
    int cnt = 0;
    for (int k = 0; k < n * n; ++ k) {
        int x, y; cin >> x >> y;
        if (vis[x][y]) {ans += "0"; continue;}
        ans += "1";
        for (auto [tx, ty] : S) {
            int dx = x - tx, dy = y - ty, g = __gcd(abs(dx), abs(dy));
            dx /= g, dy /= g;
            for (int i = x, j = y; cnt <= n * n && 0 < i && i <= n && 0 < j && j <= n; i -= dx, j -= dy)
                if (!vis[i][j]) vis[i][j] = 1, cnt ++;
            for (int i = x, j = y; cnt <= n * n && 0 < i && i <= n && 0 < j && j <= n; i += dx, j += dy)
                if (!vis[i][j]) vis[i][j] = 1, cnt ++;
        }
        S.emplace_back(x, y);
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}