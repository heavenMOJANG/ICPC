#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) cin >> a[i][j], a[i][0] += a[i][j];
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), [&](int x, int y) { return a[x][0] > a[y][0]; });
    int ans{}, fac = n * m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) ans += a[p[i]][j] * fac, fac --;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}