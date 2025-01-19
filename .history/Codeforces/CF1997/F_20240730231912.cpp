#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string g[2]; cin >> g[0] >> g[1];
    vector<vector<int>> vis(2, vector<int>(n, 0)); 
    int ans = 0, cnt = 0;
    if (g[0][0] == '.') vis[0][0] = 1, cnt = 1;
    if (g[1][0] == '.') vis[1][0] = 1, cnt = 1;
    for (int i = 1; i < n; ++ i) {
        if (g[0][i] == 'x' && g[1][i] == 'x') continue;
        if (g[0][i] == '.' && g[1][i] == 'x') {
            if (vis[0][i - 1]) vis[0][i] = vis[0][i - 1];
            else vis[0][i] = ++ cnt;
        }
        if (g[0][i] == 'x' && g[1][i] == '.') {
            if (vis[1][i - 1]) vis[1][i] = vis[1][i - 1];
            else vis[1][i] = ++ cnt;
        }
        if (g[0][i] == '.' && g[1][i] == '.') {
            if (vis[0][i - 1] || vis[1][i - 1]) {
                if (vis[0][i - 1]) vis[0][i] = vis[1][i] = vis[0][i - 1];
                else vis[0][i] = vis[1][i] = vis[1][i - 1];
            }
            else vis[0][i] = vis[1][i] = ++ cnt;
        }
    }
    if (!cnt) {
        cout << "0\n";
    } else {
        for (int i = 1; i < n - 1; ++ i) {
            if (vis[0][i] && !vis[0][i - 1] && !vis[0][i + 1] && vis[1][i - 1] && vis[1][i] && vis[1][i + 1]) ans ++;
            if (vis[1][i] && !vis[1][i - 1] && !vis[1][i + 1] && vis[0][i - 1] && vis[0][i] && vis[0][i + 1]) ans ++;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}