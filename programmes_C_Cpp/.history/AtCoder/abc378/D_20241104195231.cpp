#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int n, m, k, step[11][11], ans;
char g[11][11];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> g[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (g[i][j] == '.') bfs(i, j);
    return 0;
}