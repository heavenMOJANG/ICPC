#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector dp(n + 1, vector (n + 1, vector<int> (2)));
    vector path(n + 1, vector (n + 1, vector<char> (2)));
    int flag = 0, zx, zy;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            int x; cin >> x;
            if (!x) {
                flag = 1;
                zx = i, zy = j;
                continue;
            }
            while (x % 2 == 0) dp[i][j][0] ++, x /= 2;
            while (x % 5 == 0) dp[i][j][1] ++, x /= 5;
        }
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j) {
            if (i == 1 || j == 1) continue;
            if (i > 1 && j > 1) {
                if (dp[i - 1][j][0] > dp[i][j - 1][0]) path[i][j][0] = 'R', dp[i][j][0] += dp[i][j - 1][0];
                else path[i][j][0] = 'D', dp[i][j][0] += dp[i - 1][j][0];
                if (dp[i - 1][j][1] > dp[i][j - 1][1]) path[i][j][1] = 'R', dp[i][j][1] += dp[i][j - 1][1];
                else path[i][j][1] = 'D', dp[i][j][1] += dp[i - 1][j][1];
            } else if (i > 1) {
                path[i][j][0] = path[i][j][1] = 'D', dp[i][j][0] += dp[i - 1][j][0], dp[i][j][1] += dp[i - 1][j][1];
            } else if (j > 1) {
                path[i][j][0] = path[i][j][1] = 'R', dp[i][j][0] += dp[i][j - 1][0], dp[i][j][1] += dp[i][j - 1][1];
            }
        }
    int z;
    if (dp[n][n][1] < dp[n][n][0]) z = 1;
    else z = 0;
    if (flag && dp[n][n][z] > 0) {
        cout << "1\n";
        for (int i = 1; i < zx; ++ i) cout << 'D';
        for (int j = 1; j < zy; ++ j) cout << 'R';
        for (int i = zx + 1; i <= n; ++ i) cout << 'D';
        for (int j = zy + 1; j <= n; ++ j) cout << 'R';
        return;
    }
    cout << dp[n][n][z] << "\n";
    int x = n, y = n;
    string ans;
    while (x != 1 || y != 1) {
        ans.push_back(path[x][y][z]);
        if (path[x][y][z] == 'R') y --;
        else x --;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}