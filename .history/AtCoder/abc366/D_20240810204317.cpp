#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector a(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j)
            for(int k = 1; k <= n; ++ k) cin >> a[i][j][k];
    }
    vector pre(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    for (int x = 1; x <= n; ++ x)
        for (int y = 1; y <= n; ++ y)
            for (int z = 1; z <= n; ++ z) {
                    pre[x][y][z] = 
                    a[x - 1][y - 1][z - 1] +
                    pre[x - 1][y][z] + pre[x][y - 1][z] + pre[x][y][z - 1] -
                    pre[x - 1][y - 1][z] - pre[x - 1][y][z - 1] - pre[x][y - 1][z - 1] +
                    pre[x - 1][y - 1][z - 1];
            }
    int q; cin >> q;
    while (q --) {
        int lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cout << pre[rx][ry][rz] -
        pre[lx-1][ry][rz] - pre[rx][ly-1][rz] - pre[rx][ry][lz-1] +
        pre[lx-1][ly-1][rz] + pre[lx-1][ry][lz-1] + pre[rx][ly-1][lz-1] -
        pre[lx-1][ly-1][lz-1];
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}