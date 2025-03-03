#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w; cin >> h >> w;
    vector g(h + 2, vector<char> (w + 2));
    vector a(h + 2, vector<int> (w + 2, 0)), b = a;
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j) {
            cin >> g[i][j];
            if (g[i][j] == '#') a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + 1;
            if (g[i][j] == '?') b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + 1;
        }
    int lx = INF, ly = INF, rx{}, ry{};
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}