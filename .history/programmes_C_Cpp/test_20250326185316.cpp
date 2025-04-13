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
    for (int i = 1; i <= n; ++ i) {
        string gd; scanf("%s", &gd);
        int k; scanf("%lld", &k);
        for (int j = 1; j <= k; ++ j) {
            int v, w; scanf("%lld:%lld", &v, &w);
            g[i][v] = w;
        }
    }
    return;
}
signed main() {
    //cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}