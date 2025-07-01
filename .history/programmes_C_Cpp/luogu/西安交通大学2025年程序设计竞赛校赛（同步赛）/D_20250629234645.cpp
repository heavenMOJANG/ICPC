#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
void solve() {
    int n, m; cin >> n >> m;
    vector g(n + 2, vector<char>(m + 2, 'W'));
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> g[i][j];
    int flag{};
    {
        int ok = 1;
        vector a = g;
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j) if (a[i][j] == 'B') a[n - i + 1][j] = 'B';
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j)
                if (a[i][j] == 'B')
                    for (int k{}; k < 4; ++ k)
                        if (a[i + dx[k]][j + dy[k]] == 'B') ok = 0;
        flag &= ok;
    }
    {
        int ok = 1;
        vector b = g;
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j) if (b[i][j] == 'B') b[i][m - j + 1] = 'B';
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j)
                if (b[i][j] == 'B')
                    for (int k{}; k < 4; ++ k)
                        if (b[i + dx[k]][j + dy[k]] == 'B') ok = 0;
        flag &= ok;
    }
    cout << (flag ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}