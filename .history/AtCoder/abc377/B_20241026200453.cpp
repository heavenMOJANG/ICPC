#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string g[8];
    vector vis(8, vector<int>(8, 1));
    for (int i = 0; i < 8; ++ i) {
        cin >> g[i];
        for (int j = 0; j < 8; ++ j) {
            if (g[i][j] == '#') {
                for (int a = 0; a < 8; ++ a) vis[i][a] = 0;
                for (int b = 0; b < 8; ++ b) vis[b][j] = 0;
            }
        }
    }
    int ans{};
    for (int i = 0; i < 8; ++ i)
        for (int j = 0; j < 8; ++ j) if (vis[i][j]) ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}