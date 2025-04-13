#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; scanf("%lld", &n);
    vector g(n + 1, vector<int> (n + 1, INF));
    for (int i = 1; i <= n; ++ i) g[i][i] = 0;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) {
        string gd; scanf("%s", &gd);
        p[i] = gd == "F" ? 0 : 1;
        int k; scanf("%lld", &k);
        for (int j = 1; j <= k; ++ j) {
            int v, w; scanf("%lld:%lld", &v, &w);
            g[i][v] = w;
        }
    }
    for (int k = 1; k <= n; ++ k)
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    vector<pair<int, int>> v[2];
    for (int i = 1; i <= n; ++ i) {
        int maxn{};
        for (int j = 1; j <= n; ++ j) if (p[i] != p[j]) maxn = max(maxn, g[i][j]);
        v[p[i]].emplace_back(maxn, i);
    }
    int max0{}, max1{}
    return;
}
signed main() {
    //cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}