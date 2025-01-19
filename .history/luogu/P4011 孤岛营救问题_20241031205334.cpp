#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 20;
int n, m, p, k, s;
int g[N][N][N][N], vis[N][N][1ll << N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> p >> k;
    for (int i = 1; i <= k; ++ i) {
        int Xi, Yi, Xj, Yj, G; cin >> Xi >> Yi >> Xj >> Yj >> G;
        if (!G) g[Xi][Yi][Xj][Yj] = g[Xj][Yj][Xi][Yi] = -1;
        else g[Xi][Yi][Xj][Yj] = g[Xj][Yj][Xi][Yi] = G;
    }
    cin >> s;

    return 0;
}