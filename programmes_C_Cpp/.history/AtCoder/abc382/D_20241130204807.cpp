#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int n, m, idx;
vector<int> a(15);
vector ans(300000, vector<int>(15));
void dfs(int x) {
    if (x == n + 1) {
        idx ++;
        for (int i = 1; i <= n; ++ i) ans[idx][i] = a[i];
        return;
    }
    for (int i = a[x - 1] + 10; i <= m - (n - x) * 10; ++ i) {
        a[x] = i;
        dfs(x + 1);
    }
}
void solve() {
    cin >> n >> m;
    a[0] = -9;
    dfs(1);
    cout << idx << "\n";
    for (int i = 1; i <= idx; ++ i)
        for (int j = 1; j <= n; ++ j) cout << ans[i][j] << " \n"[j == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}