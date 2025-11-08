#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int get(int x) {
    int res{};
    while (x) x &= x - 1, res ++;
    return res;
}
int h, w, m;
vector<int> a;
vector<vector<int>> dp;
int dfs(int i, int j) {
    if (i == h) return 0;
    if (dp[i][j] != -INF) return dp[i][j];
    int res = -INF;
    for (int k{}; k < m; ++k) {
        if ((k & ~a[i]) != 0) continue;
        if (i > 0) {
            if (((j & (j >> 1)) & (k & (k >> 1))) != 0) continue;
        }
        int ndp = get(k) + dfs(i + 1, k);
        if (ndp > res) res = ndp;
    }
    if (res < 0) res = 0;
    dp[i][j] = res;
    return res;
}
void solve() {
    cin >> h >> w;
    vector g(h, vector<char> (w));
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) cin >> g[i][j];
    a.assign(h, 0);
    int tot{};
    for (int i{}; i < h; ++ i) {
        int b{};
        for (int j{}; j < w; ++ j) if (g[i][j] == '#') b |= 1 << j, tot ++;
        a[i] = b;
    }
    m = 1 << w;
    dp.assign(h, vector<int>(m, -INF));
    int cnt = dfs(0, 0);
    cout << tot - cnt << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}
