#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
int n, m, k, ans, num[11][11];
mt19937_64 rnd(time(NULL));
char g[11][11];
void dfs(int x, int y, int step) {
    
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> g[i][j], num[i][j] = rnd();
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (g[i][j] == '.') dfs(i, j, 0);
    cout << ans << "\n";
    return 0;
}